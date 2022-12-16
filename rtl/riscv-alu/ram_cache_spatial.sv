//RAM-Cache module with spatial locality.
//Spatial locality only considering 3 neighbours.
//Benefit of spatial locality is that it pre-writes next 4 values so we can read immediately
//instead of only reading once we write them when we specifically receive them, but in this case we receive its neighbour and indirectly right it
module ram_cache_spatial # (
    parameter RAM_ADDRESS_WIDTH = 32, //should be 32
    // A[15:8] = tag, A[7:4] = cache address, A[3:2] = block offset, A[1:0] = byte offset
    DATA_WIDTH = 32,
    BYTE_WIDTH = 8,
    CACHE_DATA_WIDTH = 153, //4 x 32 bit = 128 bit for data, 24 bit for tag, 1 bit for flag = 153
    CACHE_ADDRESS_WIDTH = 4
)(

//Interface signals:

    //Input:
    input logic clk,
    input logic WE, //write enable
    input logic [RAM_ADDRESS_WIDTH-1:0] A, //A[31:8] = tag, A[7:4] = set number, A[3:2] = block offset
    input logic [1:0] dataType, //input signal where 00: word, 01: byte, 10: half word
    input logic [DATA_WIDTH-1:0] WD, //write input (DataIn)

    //Output:
    output logic [DATA_WIDTH-1:0] RD //DataOut
    //output logic [DATA_WIDTH-1:0] RAM_array_value,
    //output logic [CACHE_DATA_WIDTH-1:0] cache_array_value

);

//Variables:
logic [RAM_ADDRESS_WIDTH-1:0] A_RD1;
logic [RAM_ADDRESS_WIDTH-1:0] A_RD2;
logic [RAM_ADDRESS_WIDTH-1:0] A_RD3;
logic [RAM_ADDRESS_WIDTH-1:0] A_RD4;

logic [DATA_WIDTH-1:0] RD1;
logic [DATA_WIDTH-1:0] RD2;
logic [DATA_WIDTH-1:0] RD3;
logic [DATA_WIDTH-1:0] RD4;


//Initializing Cache and cache variables:
logic [CACHE_DATA_WIDTH-1:0] cache_array [2**CACHE_ADDRESS_WIDTH-1:0];

initial begin
    $display("Loading cache.");
    $readmemh("reference/cachedata.mem", cache_array); //16 cache sets to load
    $display("Cache successfully loaded.");
end;

//Initializing RAM and RAM variables:
//logic [BYTE_WIDTH-1:0] ram_array [2**RAM_ADDRESS_WIDTH-1:0];
logic [BYTE_WIDTH-1:0] ram_array [17'h1FFFF:17'h0];

initial begin
    $display("Loading ram.");
    $readmemh("reference/sine.mem", ram_array, 17'h10000);
    $display("Ram successfully loaded.");
end;

//Word at cache:
logic [CACHE_DATA_WIDTH-1:0] cache_data;
assign cache_data = cache_array[A[7:4]]; //data in cache location given by A[7:4]

logic flagMiss; //1-Miss, 0-Hit
logic [DATA_WIDTH-1:0] outputWord;

always_comb begin //new instruction comes with new clk cycle, so flagMiss can still be used at clk posedge for current instruction
    if (!WE) begin //Read instruction so cache is checked first
        if(cache_data[152]) begin //so if V is 1 //137
            if(cache_data[151:128]==A[31:8]) begin //compare tag
                //use byte offset to determine which byte to output within the word
                //Use mux:
                //Select data based on block offset
                assign outputWord = A[3] ? (A[2] ? cache_data[127:96] : cache_data[95:64]) : (A[2] ? cache_data[63:32] : cache_data[31:0]);
                //Choosing byte within RD:
                //Bits A[1:0] is used for byte offset:
                if (dataType==2'b00) begin //so 00 dataType, so output entire Word
                    assign RD = outputWord;
                end
                else begin //byte, the byte chosen is based on byte offset
                    case (A[1:0]) //byte offset
                        2'b00: begin //so use 1st byte of outputWord
                            assign RD = {{24{1'b0}}, outputWord[7:0]};
                        end
                        2'b01: begin //use 2nd byte of outputWord
                            assign RD = {{24{1'b0}}, outputWord[15:8]};
                        end
                        2'b10: begin //use 3rd byte of outputWord
                            assign RD = {{24{1'b0}}, outputWord[23:16]};
                        end
                        2'b11: begin //use 4th byte of outputWord
                            assign RD = {{24{1'b0}}, outputWord[31:24]};
                        end
                        default: $display("No dataType selected. Please choose word, byte or halfword.");
                endcase
                end

                assign flagMiss = 1'b0; //hit

                //Don't cares
                assign A_RD1 = 32'b0;
                assign A_RD2 = 32'b0;
                assign A_RD3 = 32'b0;
                assign A_RD4 = 32'b0;

                //Concatenating 4 bytes gives the data word RD
                assign RD1 = 32'b0;
                assign RD2 = 32'b0;
                assign RD3 = 32'b0;
                assign RD4 = 32'b0;
            end
            else begin //tag doesn't match so miss, so read from RAM
                //Outputs desired data type 
                case (dataType)
                    2'b00: begin //00 then use word
                        assign RD = {ram_array[A+3], ram_array[A+2], ram_array[A+1], ram_array[A]}; 
                    end 
                    2'b01: begin //01 then use byte unsigned - changed accordingly in ALU control
                        assign RD = {{24{1'b0}}, ram_array[A]};
                    end
                    2'b10: begin //10 then use half word unsigned - changed accordingly in ALU control
                        assign RD = {{16{1'b0}}, ram_array[A+1], ram_array[A]};
                    end
                    default: $display("No dataType selected. Please choose word, byte or halfword.");
                endcase
                //assign RD = {ram_array[A+3], ram_array[A+2], ram_array[A+1], ram_array[A]};
                assign flagMiss = 1'b1; //miss

                //Addresses of neighbours in main mem that are fetched and written to same cache set.
                //Only write neighbours if we have cache miss situation.
                assign A_RD1 = {A[31:4], 2'b00, A[1:0]};
                assign A_RD2 = {A[31:4], 2'b01, A[1:0]};
                assign A_RD3 = {A[31:4], 2'b10, A[1:0]};
                assign A_RD4 = {A[31:4], 2'b11, A[1:0]};

                //Concatenating 4 bytes gives the data word RD
                assign RD1 = {ram_array[A_RD1+3],ram_array[A_RD1+2],ram_array[A_RD1+1],ram_array[A_RD1]};
                assign RD2 = {ram_array[A_RD2+3],ram_array[A_RD2+2],ram_array[A_RD2+1],ram_array[A_RD2]};
                assign RD3 = {ram_array[A_RD3+3],ram_array[A_RD3+2],ram_array[A_RD3+1],ram_array[A_RD3]};
                assign RD4 = {ram_array[A_RD4+3],ram_array[A_RD4+2],ram_array[A_RD4+1],ram_array[A_RD4]};
            end
        end
        else begin //0 V-bit so miss, so read fom RAM
            //Outputs desired data type 
            case (dataType)
                2'b00: begin //00 then use word
                    assign RD = {ram_array[A+3], ram_array[A+2], ram_array[A+1], ram_array[A]}; 
                end 
                2'b01: begin //01 then use byte unsigned - changed accordingly in ALU control
                    assign RD = {{24{1'b0}}, ram_array[A]};
                end
                2'b10: begin //10 then use half word unsigned - changed accordingly in ALU control
                    assign RD = {{16{1'b0}}, ram_array[A+1], ram_array[A]};
                end
                default: $display("No dataType selected. Please choose word, byte or halfword.");
            endcase
            assign flagMiss = 1'b1; //miss

            //Addresses of neighbours in main mem that are fetched and written to same cache set
            assign A_RD1 = {A[31:4], 2'b00, A[1:0]};
            assign A_RD2 = {A[31:4], 2'b01, A[1:0]};
            assign A_RD3 = {A[31:4], 2'b10, A[1:0]};
            assign A_RD4 = {A[31:4], 2'b11, A[1:0]};

            //Concatenating 4 bytes gives the data word RD
            assign RD1 = {ram_array[A_RD1+3],ram_array[A_RD1+2],ram_array[A_RD1+1],ram_array[A_RD1]};
            assign RD2 = {ram_array[A_RD2+3],ram_array[A_RD2+2],ram_array[A_RD2+1],ram_array[A_RD2]};
            assign RD3 = {ram_array[A_RD3+3],ram_array[A_RD3+2],ram_array[A_RD3+1],ram_array[A_RD3]};
            assign RD4 = {ram_array[A_RD4+3],ram_array[A_RD4+2],ram_array[A_RD4+1],ram_array[A_RD4]};
        end
    end
    else begin //if write enable then don't do anything, rewrite value in positive clock edge
        assign RD = 32'b0;
        assign flagMiss = 1'b0; //so it doesn't rewrite

        //Don't cares
        assign A_RD1 = 32'b0;
        assign A_RD2 = 32'b0;
        assign A_RD3 = 32'b0;
        assign A_RD4 = 32'b0;

        //Concatenating 4 bytes gives the data word RD
        assign RD1 = 32'b0;
        assign RD2 = 32'b0;
        assign RD3 = 32'b0;
        assign RD4 = 32'b0;

    end
end

always_ff @(posedge clk) begin 
    //synchronous write
    if (WE) begin //if writing to RAM then also write to cache so that cache value is updated
            case (dataType)
                2'b00: begin //write word to mem location given by A
                    ram_array[A] <= WD[7:0]; //LS Byte
                    ram_array[A+1] <= WD[15:8];
                    ram_array[A+2] <= WD[23:16];
                    ram_array[A+3] <= WD[31:24]; //MS Byte
                    //Writing word to specific data in cache:
                    //Using block offset of A, so A[3:2]
                    case (A[3:2]) 
                        2'b00: begin
                            cache_array[A[7:4]] <= {1'b1, A[31:8], cache_data[127:96], cache_data[95:64], cache_data[63:32], WD};
                        end
                        2'b01: begin
                            cache_array[A[7:4]] <= {1'b1, A[31:8], cache_data[127:96], cache_data[95:64], WD, cache_data[31:0]};
                        end
                        2'b10: begin
                            cache_array[A[7:4]] <= {1'b1, A[31:8], cache_data[127:96], WD, cache_data[63:32], cache_data[31:0]};
                        end
                        2'b11: begin
                            cache_array[A[7:4]] <= {1'b1, A[31:8], WD, cache_data[95:64], cache_data[63:32], cache_data[31:0]};
                        end
                        default: $display("No block offset present.");
                    endcase
                end
                2'b01: begin //write byte to mem location given by A
                    ram_array[A] <= WD[7:0];
                    //cache_array[A[7:2]] <= {1'b1, A[15:8], {24{1'b0}}, WD[7:0]}; //writing byte to cache
                    //Writing byte to specific data in cache:
                    case (A[3:2]) 
                        2'b00: begin
                            cache_array[A[7:4]] <= {1'b1, A[31:8], cache_data[127:96], cache_data[95:64], cache_data[63:32], {24{1'b0}}, WD[7:0]};
                        end
                        2'b01: begin
                            cache_array[A[7:4]] <= {1'b1, A[31:8], cache_data[127:96], cache_data[95:64], {24{1'b0}}, WD[7:0], cache_data[31:0]};
                        end
                        2'b10: begin
                            cache_array[A[7:4]] <= {1'b1, A[31:8], cache_data[127:96], {24{1'b0}}, WD[7:0], cache_data[63:32], cache_data[31:0]};
                        end
                        2'b11: begin
                            cache_array[A[7:4]] <= {1'b1, A[31:8], {24{1'b0}}, WD[7:0], cache_data[95:64], cache_data[63:32], cache_data[31:0]};
                        end
                        default: $display("No block offset present.");
                    endcase
                end
                2'b10: begin
                    ram_array[A] <= WD[7:0]; //LS Byte
                    ram_array[A+1] <= WD[15:8];
                    //cache_array[A[7:2]] <= {1'b1, A[15:8], {16{1'b0}}, WD[15:8], WD[7:0]}; //writing halfword to cache
                    //Writing halfword to specific data in cache:
                    case (A[3:2]) 
                        2'b00: begin
                            cache_array[A[7:4]] <= {1'b1, A[31:8], cache_data[127:96], cache_data[95:64], cache_data[63:32], {16{1'b0}}, WD[15:0]};
                        end
                        2'b01: begin
                            cache_array[A[7:4]] <= {1'b1, A[31:8], cache_data[127:96], cache_data[95:64], {16{1'b0}}, WD[15:0], cache_data[31:0]};
                        end
                        2'b10: begin
                            cache_array[A[7:4]] <= {1'b1, A[31:8], cache_data[127:96], {16{1'b0}}, WD[15:0], cache_data[63:32], cache_data[31:0]};
                        end
                        2'b11: begin
                            cache_array[A[7:4]] <= {1'b1, A[31:8], {16{1'b0}}, WD[15:0], cache_data[95:64], cache_data[63:32], cache_data[31:0]};
                        end
                        default: $display("No block offset present.");
                    endcase
                end
                default: $display("No dataType selected. Please choose word, byte or halfword.");
            endcase
    end
    else begin //if !WE then check flag as we must be reading so flag must've been evaluated
        //This is temporal locality, so most recent accessed/fetched data from main mem is stored in cache
        //Add spatial locality, so copy neighbouring data into cache
        if (flagMiss) begin //Write to cache if miss
            //Cache address given by A[7:4], and is filled with all neighbours.
            cache_array[A[7:4]] <= {1'b1, A[31:8], RD4, RD3, RD2, RD1};  
        end
    end
end

//For debugging
//assign RAM_array_value = ram_array[3];
//assign cache_array_value = cache_array[A[7:4]];

endmodule


