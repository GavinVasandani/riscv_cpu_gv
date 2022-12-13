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

//Initializing RAM and RAM variables:
logic [BYTE_WIDTH-1:0] ram_array [2**RAM_ADDRESS_WIDTH-1:0];

initial begin
    $display("Loading ram.");
    $readmemh("sine.mem", ram_array); //65536 values so 16 bits address width
    $display("Ram successfully loaded.");
end;

//Word at cache:
logic [CACHE_DATA_WIDTH-1:0] cache_data;
assign cache_data = cache_array[A[7:2]];

logic flagMiss; //1-Miss, 0-Hit

always_ff @(posedge clk) begin 
    //synchronous write
    if (WE) begin
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
        if(cache_data[40]) begin //so if V is 1
            if(cache_data[39:32]==A[15:8]) begin //compare tag
                assign RD = cache_data[31:0]; //output immediately that DataOut is 31 bit data stored in cache, as its read its async
                assign flagMiss = 1'b0; //hit
            end
            else begin //tag doesn't match so miss, so read from RAM
                assign RD = {ram_array[A+3], ram_array[A+2], ram_array[A+1], ram_array[A]};
                assign flagMiss = 1'b1; //miss
            end
        end
        else begin //0 V-bit so miss, so read fom RAM
            assign RD = {ram_array[A+3], ram_array[A+2], ram_array[A+1], ram_array[A]};
            assign flagMiss = 1'b1; //miss
        end
    end
end

always_ff @(posedge clk) begin
    if (flagMiss) begin //Write to cache if miss
      cache_array[A[7:2]] <= {1'b1, A[15:8], ram_array[A+3], ram_array[A+2], ram_array[A+1], ram_array[A]};  
    end
end

//For debugging
assign RAM_array_value = ram_array[3];
assign cache_array_value = cache_array[A[7:2]];

endmodule


//Currently RAM-cache only outputs word and cache stores word, byte or halfword.
//RAM-cache can store word, half word or byte.
//Add functionality for cache outputting halfword or byte.
