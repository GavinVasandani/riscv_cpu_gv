module ram #(
    parameter ADDRESS_WIDTH = 12, // needs to be 12 bit wide, look at memory map of final project for reasoning
    //memory addresses reserved from data memory is 0x00001000 to 0x00001FFF, so 12 bit address width, so 4096 referencable mem locations.
    DATA_WIDTH = 32, // 32 bit value stored in mem location of RAM - since it's byte addressed we store data in 4 addresses - confirm with GTA
    BYTE_WIDTH = 8
)(
    input logic clk,
    input logic WE, //write enable
    input logic dataType, //input signal, where 0: word, 1: byte
    //Input signal to determine whether store byte or store word:
    //if store byte then ram_array[A] = rd2 [7:0]
    //input logic WW, //write word
    //input logic RB, //read byte, signal that if 1 outputs byte from ram instead of word, by default word is outputted
    input logic [ADDRESS_WIDTH-1:0] A, // address, to be taken from output of ALU, 12 bit address so that we can address all mem locations in data mem
    input logic [DATA_WIDTH-1:0] WD, // write input, to be taken from rd2
    output logic [DATA_WIDTH-1:0] RD // read output
);

logic [BYTE_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0]; //each mem location of array stores a byte-width so 8 bits
logic byteAssign;

// you don't need to initialize a ram array with 0s, there is no need for loadmemh operation
//yeah but need to load in some initial values to the ram so probably do need a loadmemh operation

//Include signal to differentiate word: 0, byte: 1

//RD is output and is 32 bits so 4 8-bits combined:
//Check if ordering assignment is correct should it be [A+3], [A+2], ... 
//LS Byte should be ram_array[A], MS Byte is ram_array[A+3]
if (dataType) begin
    //sign extend 8 bit output (signed):
    byteAssign = ram_array[A];
    assign RD = {{24{byteAssign[7]}}, byteAssign}};
end
else begin
    assign RD = {ram_array[A], ram_array[A+1], ram_array[A+2], ram_array[A+3]}; // asynchronous read - have an iisue here, want to confirm with the GTA
end
//if each address stores a 32-bit word then RD would be 128 bits, so each address needs to store 1 byte, so 8 bit and then combined gives 32-bit word

always_ff @(posedge clk) begin
    if (WE) begin// synchronous write
        if (!dataType) begin
    //last 2 bytes (16 bits) of address is same but filling a word as each mem location only holds 8 bits we split:
            ram_array[A] <= WD[7:0]; //LS Byte
            ram_array[A+1] <= WD[15:8];
            ram_array[A+2] <= WD[23:16];
            ram_array[A+3] <= WD[31:24]; //MS Byte
        end
        else begin //so writing a byte
            ram_array[A] <= WD[7:0];
        end
    end
end
endmodule

// please ask the GTA if this implementation is correct, it is taken from the memory map so it should be fine. The only issue is the input address is 32 bits wide.