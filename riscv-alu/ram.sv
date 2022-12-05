module ram #(
    parameter ADDRESS_WIDTH = 12, // needs to be 12 bit wide, look at memory map of final project for reasoning
    //memory addresses reserved from data memory is 0x00001000 to 0x00001FFF, so 12 bit address width, so 4096 referencable mem locations.
    DATA_WIDTH = 32 // 32 bit value stored in mem location of RAM - since it's byte addressed we store data in 4 addresses - confirm with GTA
)(
    input logic clk,
    input logic WE, //write enable
    input logic [ADDRESS_WIDTH-1:0] A, // address, to be taken from output of ALU, 12 bit address so that we can address all mem locations in data mem
    input logic [DATA_WIDTH-1:0] WD, // write input, to be taken from rd2
    output logic [DATA_WIDTH-1:0] RD // read output
);

logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

// you don't need to initialize a ram array with 0s, there is no need for loadmemh operation
//yeah but need to load in some initial values to the ram so probably do need a loadmemh operation

assign RD = {ram_array[A], ram_array[A+1], ram_array[A+2], ram_array[A+3]}; // asynchronous read - have an iisue here, want to confirm with the GTA
//if each address stores a 32-bit word then RD would be 128 bits, so each address needs to store 1 byte, so 8 bit and then combined gives 32-bit word

always_ff @(posedge clk) begin
    if (WE) // synchronous write
    //last 2 bytes (16 bits) of word 
        ram_array[A] <= WD[];
        ram_array[A+1] <= WD[];
        ram_array[A+2] <= WD[15:8];
        ram_array[A+3] <= WD[7:0];
end
endmodule

// please ask the GTA if this implementation is correct, it is taken from the memory map so it should be fine. The only issue is the input address is 32 bits wide.