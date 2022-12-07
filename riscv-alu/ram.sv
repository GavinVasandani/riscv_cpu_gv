module ram #(
    parameter ADDRESS_WIDTH = 32, // needs to be 17 bit wide, look at memory map of final project for reasoning
    //memory addresses reserved from data memory is 0x00001000 to 0x00001FFF, so 12 bit address width, so 4096 referencable mem locations.
    DATA_WIDTH = 32, // 32 bit value stored in mem location of RAM - since it's byte addressed we store data in 4 addresses - confirm with GTA
    BYTE_WIDTH = 8
)(
    input logic clk,
    input logic WE, //write enable
    input logic [1:0] dataType, //input signal, where 00: word, 01: byte, 10: half word
    input logic [ADDRESS_WIDTH-1:0] A, // address, to be taken from output of ALU, 12 bit address so that we can address all mem locations in data mem
    input logic [DATA_WIDTH-1:0] WD, // write input, to be taken from rd2
    output logic [DATA_WIDTH-1:0] RD // read output
);

logic [BYTE_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0]; //each mem location of array stores a byte-width so 8 bits
logic [7:0] byteAssign;
logic [15:0] halfwordAssign;

// you don't need to initialize a ram array with 0s, there is no need for loadmemh operation
//yeah but need to load in some initial values to the ram so probably do need a loadmemh operation

//Include signal to differentiate word: 0, byte: 1

//RD is output and is 32 bits so 4 8-bits combined:
always_comb begin
    case (dataType)
        2'b00: begin //00 then use word
            assign RD = {ram_array[A+3], ram_array[A+2], ram_array[A+1], ram_array[A]}; // asynchronous read - have an iisue here, want to confirm with the GTA
        end 
        2'b01: begin //01 then use byte
            byteAssign = ram_array[A];
            assign RD = {{24{byteAssign[7]}}, byteAssign};
        end
        2'b10: begin //10 then use half word
            halfwordAssign = {ram_array[A+1], ram_array[A]};
            assign RD = {{16{halfwordAssign[15]}}, halfwordAssign};
        end
        default: $display("No dataType selected. Please choose word, byte or halfword.");
    endcase
end

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