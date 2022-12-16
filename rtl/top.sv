`include "riscv-final-pc/top_pc.sv"
`include "riscv-final-pc/rom.sv"
`include "riscv-final-pc/pc_reg.sv"
`include "riscv-alu/topLevelALU.sv"
`include "riscv-alu/regfile.sv"
`include "riscv-alu/regfileALU.sv"
`include "riscv-alu/regfileMux.sv"
`include "riscv-alu/resultPCMux.sv"
`include "riscv-alu/resultSrcMux.sv"
`include "riscv-alu/ram_cache_spatial.sv"
`include "riscv-final-controlunit/control.sv"
`include "riscv-final-controlunit/ext.sv"
`include "riscv-final-controlunit/ALUDecoder.sv"
`include "riscv-final-controlunit/mainDecoder.sv"

module top#(
    parameter ADDRESS_WIDTH = 32,
    DATA_WIDTH = 32
)(
    input logic             trigger, 
    input logic             clk,
    input logic             rst,
    output logic [ADDRESS_WIDTH-1:0] a0,
    output logic [ADDRESS_WIDTH-1:0] delay

);

    logic RegWrite;
    logic [DATA_WIDTH-1:0] PC_instr;
    logic PCsrc;
    logic [4:0] rs1;
    logic [4:0] rs2;
    logic [4:0] rd;
    logic ALUSrc;
    logic [3:0] ALU_ctrl;
    logic EQ;
    logic [1:0] DataType;
    logic [1:0] J;
    logic [DATA_WIDTH-1:0] ImmOp;
    logic [ADDRESS_WIDTH-1:0] jalr_PC;
    logic [DATA_WIDTH-1:0] next_PC;
    logic [2:0]  ImmSrc;
    logic [1:0] MemWrite;
    logic ResultSrc;
    logic JumpSel;

    assign JumpSel = J[1] | J[0];
    assign rs1 = PC_instr[19:15];
    assign rs2 = PC_instr[24:20];
    assign rd  = PC_instr[11:7];

top_pc myPC(
    .ImmOp  (ImmOp),
    .jalr_PC (jalr_PC),
    .PCsrc  (PCsrc),
    .J          (J),
    .clk    (clk),
    .rst    (rst),
    .instr   (PC_instr),
    .next_PC (next_PC)
);

ext sign_extend(
    .imm    (PC_instr[31:7]),
    .ImmSrc (ImmSrc),
    .ImmExt  (ImmOp)
);

control control_unit(
    .op     (PC_instr[6:0]),
    .funct3 (PC_instr[14:12]),
    .funct75(PC_instr[30]),
    .Zero     (EQ),
    .ALUControl (ALU_ctrl),
    .ALUSrc     (ALUSrc),
    .ImmSrc     (ImmSrc),
    .PCSrc      (PCsrc),
    .ResultSrc  (ResultSrc),
    .MemWrite   (MemWrite),
    .RegWrite   (RegWrite),
    .DataType   (DataType),
    .J          (J)
);

topLevelALU ALU(
    .trigger (trigger),
    .clk    (clk),
    .rs1    (rs1),
    .rs2    (rs2),
    .rd     (rd),
    .regFileWen (RegWrite),
    .ALUSrc (ALUSrc),
    .ImmOp  (ImmOp),
    .newPC (next_PC),
    .ALU_ctrl (ALU_ctrl),
    .MemWrite (MemWrite),
    .dataType (DataType),
    .SrcSel (ResultSrc),
    .JumpSel    (JumpSel),
    .eq     (EQ),
    .a0     (a0),
    .delay  (delay),
    .jalrOutput (jalr_PC)
);


endmodule


