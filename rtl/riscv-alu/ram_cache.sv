//Combined ram cache module - specific for 16 bit address width RAM
//Check whether cache is also byte addressed (Don't think it is)
//RAM cache works, just need to implement full functionality of normal RAM and use good test program
module ram_cache # (
    parameter RAM_ADDRESS_WIDTH = 16, //should be 32
    DATA_WIDTH = 32,
    BYTE_WIDTH = 8,
    CACHE_DATA_WIDTH = 41, //32 bit for data, 8 bit for tag, 1 bit for flag = 41
    CACHE_ADDRESS_WIDTH = 6
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

initial begin
    $display("Loading cache.");
    $readmemh("cachedata.mem", cache_array); //64 mem locations of 41 bits each value
    $display("Cache successfully loaded.");
end;

//Initializing RAM and RAM variables:
//logic [BYTE_WIDTH-1:0] ram_array [2**RAM_ADDRESS_WIDTH-1:0]; //each mem location of array stores a byte-width so 8 bits
logic [BYTE_WIDTH-1:0] ram_array [2**RAM_ADDRESS_WIDTH-1:0];

initial begin
    $display("Loading ram.");
    $readmemh("sine.mem", ram_array); //65536 values so 16 bits address width
    $display("Ram successfully loaded.");
end;

//Cache to refer to:
//logic [CACHE_ADDRESS_WIDTH-1:0] cache_address;
//assign cache_address = A[7:2];
//assign cache_address = A[(1+CACHE_ADDRESS_WIDTH):2]; //so 6 bit for cach e address in this case

//Word at cache: //Check if allowed to do values chronologically
logic [CACHE_DATA_WIDTH-1:0] cache_data;
assign cache_data = cache_array[A[7:2]];

logic flagMiss; //1-Miss, 0-Hit
//assign cache_data = cache_array[cache_address]; //this is entire 57 bit data stored in cache

//Checking if writing to RAM instruction: No need to write to Cache if writing to RAM
always_ff @(posedge clk) begin 
    //synchronous write
    if (WE) begin
            case (dataType)
                2'b00: begin //write word to mem location given by A
                    ram_array[A] <= WD[7:0]; //LS Byte
                    ram_array[A+1] <= WD[15:8];
                    ram_array[A+2] <= WD[23:16];
                    ram_array[A+3] <= WD[31:24]; //MS Byte
                end
                2'b01: begin //write byte to mem location given by A
                    ram_array[A] <= WD[7:0];
                end
                2'b10: begin
                    ram_array[A] <= WD[7:0]; //LS Byte
                    ram_array[A+1] <= WD[15:8];
                end
                default: $display("No dataType selected. Please choose word, byte or halfword.");
            endcase
    end
end

always_comb begin //new instruction comes with new clk cycle, so flagMiss can still be used at clk posedge for current instruction
    if (!WE) begin //So read instruction so cache is used
        //1. Refer to cache to see if data at A is in cache:
        //Combinational/immediate read from cache:
        if(cache_data[40]) begin //so if V is 1
            if(cache_data[39:32]==A[15:8]) begin //compare 24 bit tag in cache to A[31:5] to see if cache contains correct mem location value
                //if true then output data in cache_data
                assign RD = cache_data[31:0]; //output immediately that DataOut is 31 bit data stored in cache, as its read its async
                assign flagMiss = 1'b0;
            end
            else begin
                assign RD = {ram_array[A+3], ram_array[A+2], ram_array[A+1], ram_array[A]};
                assign flagMiss = 1'b1;
            end
        end
        else begin //in any other case: wrong tag or V is 0, RD is assigned to RAM value
            assign RD = {ram_array[A+3], ram_array[A+2], ram_array[A+1], ram_array[A]};
            assign flagMiss = 1'b1;
        end
    end
end //these flagMiss values are used immediately when clock is posedge 

always_ff @(posedge clk) begin
    if (flagMiss) begin //combinational read from ram_array for ram_array[A+3],...,ram_array[A], so done immediately when clk posedge
      cache_array[A[7:2]] <= {1'b1, A[15:8], ram_array[A+3], ram_array[A+2], ram_array[A+1], ram_array[A]};  
    end
end

assign RAM_array_value = ram_array[4];
assign cache_array_value = cache_array[1];

endmodule


//Currently RAM only outputs word and cache only stores word, no byte or halfword.
//RAM can store word, half word or byte.
