module rom #(
    parameter ADDRESS_WIDTH = 12, // we use only 12 bits (from 000 to FFF) to accommodate the entire program. See readme for more details.
    DATA_WIDTH = 8 // data width of each instruction has to be 8. This allows for 4 bytes to be concatenated to form one word.
)(
    input logic [ADDRESS_WIDTH-1:0] PC,
    output logic [31:0]   instr
);

logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];

initial begin
    $display("Loading rom.");
    $readmemh("src/myprog/counter.s.hex", rom_array);
    $display("Rom successfully loaded.");
end;

// asynchronous assignment, should be blocking
assign instr = {rom_array[PC+3], rom_array[PC+2], rom_array[PC+1], rom_array[PC]};
// note, always leave some space / a line after your memory file. Verilator doesn't seem to pick up the very last signal for some reason otherwise.
// byte addressing causes increments of 4.


endmodule
