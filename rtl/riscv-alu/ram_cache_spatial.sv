//RAM-Cache module with spatial locality.
//Spatial locality only considering 3 neighbours.
//Benefit of spatial locality is that it pre-writes next 4 values so we can read immediately
//instead of only reading once we write them when we specifically receive them, but in this case we receive its neighbour and indirectly right it
module ram_cache_spatial # (
    parameter RAM_ADDRESS_WIDTH = 16, //should be 32
    // A[15:8] = tag, A[7:4] = cache address, A[3:2] = block offset, A[1:0] = byte offset
    DATA_WIDTH = 32,
    BYTE_WIDTH = 8,
    CACHE_DATA_WIDTH = 137, //4 x 32 bit = 128 bit for data, 8 bit for tag, 1 bit for flag = 137
    CACHE_ADDRESS_WIDTH = 4
)(

//Interface signals:

    //Input:
    input logic clk,
    input logic [RAM_ADDRESS_WIDTH-1:0] A,
    input logic WE, //write enable
    input logic [DATA_WIDTH-1:0] WD, //write input (DataIn)
    input logic [1:0] dataType, //input signal where 00: word, 01: byte, 10: half word

    //Output:
    output logic [DATA_WIDTH-1:0] RD, //DataOut
    output logic [DATA_WIDTH-1:0] RAM_array_value,
    output logic [CACHE_DATA_WIDTH-1:0] cache_array_value

);

//Initializing Cache and cache variables:
logic [CACHE_DATA_WIDTH-1:0] cache_array [2**CACHE_ADDRESS_WIDTH-1:0];

//Initializing RAM and RAM variables:
logic [BYTE_WIDTH-1:0] ram_array [2**RAM_ADDRESS_WIDTH-1:0];

initial begin
    $display("Loading ram.");
    $readmemh("sine.mem", ram_array); //65536 values so 16 bits address width
    $display("Ram successfully loaded.");
end;

always_ff @(posedge clk) begin 
    //synchronous write
    if (WE) begin //if writing to RAM then also write to cache so that cache value is updated
            case (dataType)
                2'b00: begin //write word to mem location given by A
                    ram_array[A] <= WD[7:0]; //LS Byte
                    ram_array[A+1] <= WD[15:8];
                    ram_array[A+2] <= WD[23:16];
                    ram_array[A+3] <= WD[31:24]; //MS Byte
                    cache_array[A[7:2]] <= {1'b1, A[15:8], WD}; //write word to cache
                end
                2'b01: begin //write byte to mem location given by A
                    ram_array[A] <= WD[7:0];
                    cache_array[A[7:2]] <= {1'b1, A[15:8], {24{1'b0}}, WD[7:0]}; //writing byte to cache
                end
                2'b10: begin
                    ram_array[A] <= WD[7:0]; //LS Byte
                    ram_array[A+1] <= WD[15:8];
                    cache_array[A[7:2]] <= {1'b1, A[15:8], {16{1'b0}}, WD[15:8], WD[7:0]}; //writing halfword to cache
                end
                default: $display("No dataType selected. Please choose word, byte or halfword.");
            endcase
    end
end

always_comb begin //new instruction comes with new clk cycle, so flagMiss can still be used at clk posedge for current instruction
    if (!WE) begin //Read instruction so cache is checked first
        if(cache_data[136]) begin //so if V is 1
            if(cache_data[135:128]==A[15:8]) begin //compare tag
                //Use mux:
                //Select data based on block offset
                assign RD = A[3] ? (A[2] ? cache_data[127:96] : cache_data[95:64]) : (A[2] ? cache_data[63:32] : cache_data[31:0]);
                assign flagMiss = 1'b0; //hit
            end
            else begin //tag doesn't match so miss, so read from RAM
                assign RD = {ram_array[A+3], ram_array[A+2], ram_array[A+1], ram_array[A]};
                assign flagMiss = 1'b1; //miss

                //Logic: //Writing to cache, writing outputted value and its neighbours.
      //The neighbours we write aren't just next 3 values, it's the rest of the block offset, so:
      //if I write mem[0x04] to cache set 0, and data within cache that is assigned to mem[0x04] is 01 then must write 10,11 to next data values and 00 to prev data value
      //but use same memory address just change block offset and fetch that value and store in data cache
      //Fetch all data from main mem with same mem address but block offset varies: 00, 01, 10, 11:
      //Copy mem address but use 00 for block offset: A[15:4], A[3:2] = 00, A[1:0]

                assign A_RD1 = {A[15:4], 2'b00, A[1:0]};
                assign A_RD2 = {A[15:4], 2'b01, A[1:0]};
                assign A_RD3 = {A[15:4], 2'b10, A[1:0]};
                assign A_RD4 = {A[15:4], 2'b11, A[1:0]};

                assign RD1 = ram_array[A_RD1];
                assign RD2 = ram_array[A_RD2];
                assign RD3 = ram_array[A_RD3];
                assign RD4 = ram_array[A_RD4];
            end
        end
        else begin //0 V-bit so miss, so read fom RAM
            assign RD = {ram_array[A+3], ram_array[A+2], ram_array[A+1], ram_array[A]};
            assign flagMiss = 1'b1; //miss

            assign A_RD1 = {A[15:4], 2'b00, A[1:0]};
            assign A_RD2 = {A[15:4], 2'b01, A[1:0]};
            assign A_RD3 = {A[15:4], 2'b10, A[1:0]};
            assign A_RD4 = {A[15:4], 2'b11, A[1:0]};

            assign RD1 = ram_array[A_RD1];
            assign RD2 = ram_array[A_RD2];
            assign RD3 = ram_array[A_RD3];
            assign RD4 = ram_array[A_RD4];
        end
    end
end

always_ff @(posedge clk) begin
    //This is temporal locality, so most recent accessed/fetched data from main mem is stored in cache
    //Add spatial locality, so copy neighbouring data into cache
    if (flagMiss) begin //Write to cache if miss

      assign A_RD1 = {A[15:4], 2'b00, A[1:0]};
      assign A_RD2 = {A[15:4], 2'b01, A[1:0]};
      assign A_RD3 = {A[15:4], 2'b10, A[1:0]};
      assign A_RD4 = {A[15:4], 2'b11, A[1:0]};

      assign RD1 = ram_array[A_RD1];
      assign RD2 = ram_array[A_RD2];
      assign RD3 = ram_array[A_RD3];
      assign RD4 = ram_array[A_RD4];

      cache_array[A[7:4]] <= {1'b1, A[15:8], RD4, RD3, RD2, RD1};  
    
    end
end

//For debugging
assign RAM_array_value = ram_array[3];
assign cache_array_value = cache_array[A[7:2]];

endmodule