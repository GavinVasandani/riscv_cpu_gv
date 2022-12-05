module ram #(
    parameter ADDRESS_WIDTH = 17, // needs to be 17 bits wide, look at memory map of final project for reasoning
    DATA_WIDTH = 32 // 32 bit value stored in mem location of RAM - since it's byte addressed we store data in 4 addresses - confirm with GTA
)(
    input logic clk,
    input logic WE, //write enable
    input logic [ADDRESS_WIDTH-1:0] A, // address, to be taken from output of ALU, 12 bit address so that we can address all mem locations in data mem
    input logic [DATA_WIDTH-1:0] WD, // write input, to be taken from rd2
    output logic [DATA_WIDTH-1:0] RD // read output
);

logic [7:0] ram_array [2**ADDRESS_WIDTH-1:0];

// you don't need to initialize a ram array with 0s, there is no need for loadmemh operation

assign RD = {ram_array[A+3], ram_array[A+2], ram_array[A+1], ram_array[A]}; // asynchronous read - have an issue here, want to confirm with the GTA

always_ff @(posedge clk) begin
    if (WE) // synchronous write
        ram_array[A+3] <= WD[31:24];
        ram_array[A+2] <= WD[23:16];
        ram_array[A+1] <= WD[15:8];
        ram_array[A] <= WD[7:0];
end
endmodule

// please ask the GTA if this implementation is correct, it is taken from the memory map so it should be fine. The only issue is the input address is 32 bits wide.