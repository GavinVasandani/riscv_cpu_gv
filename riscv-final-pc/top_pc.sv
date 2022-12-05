`include "rom.sv"
`include "pc_reg.sv"

module top_pc #(
        parameter ADDRESS_WIDTH = 12,
    DATA_WIDTH = 32
)(
  input logic [DATA_WIDTH-1:0] ImmOp,
  input logic                     PCsrc,
  input logic                     clk,
  input logic                     rst,
  output logic [DATA_WIDTH-1:0]   instr
);

  logic [ADDRESS_WIDTH-1:0] internalImmOp = ImmOp[11:0];

  logic [ADDRESS_WIDTH-1:0] PC;

pcreg pcReg(internalImmOp, PCsrc, clk, rst, PC);

rom pcRom(PC, instr);

endmodule
