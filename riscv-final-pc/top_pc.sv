`include "rom.sv"
`include "pc_reg.sv"

module top_pc #(
        parameter ADDRESS_WIDTH = 32,
    DATA_WIDTH = 32
)(
  input logic [ADDRESS_WIDTH-1:0] ImmOp,
  input logic                     PCsrc,
  input logic                     clk,
  input logic                     rst,
  output logic [DATA_WIDTH-1:0]   instr,
  output logic [ADDRESS_WIDTH-1:0] next_PC
);

  logic [ADDRESS_WIDTH-1:0] PC;

pc_reg pcReg(ImmOp, PCsrc, clk, rst, PC, next_PC);

rom pcRom(PC, instr);

endmodule
