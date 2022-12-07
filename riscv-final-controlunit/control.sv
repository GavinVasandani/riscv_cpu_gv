module control(

    //input logic clk,

    input logic [6:0]   op,
    input logic [2:0]   funct3,
    input logic         funct75,   //funct7[5]
    input logic         Zero,

    output logic        PCSrc,
    output logic        ResultSrc,
    output logic        MemWrite,
    output logic [3:0]  ALUControl,
    output logic        ALUSrc,
    output logic [1:0]  ImmSrc,
    output logic        RegWrite,
    output logic [1:0]  DataType,
    output logic        J           //JAL
);

logic Branch;
logic [1:0] ALUOp;

mainDecoder m(
    .op(op), 
    .ImmSrc(ImmSrc),
    .Branch(Branch), 
    .ResultSrc(ResultSrc), 
    .MemWrite(MemWrite), 
    .ALUSrc(ALUSrc), 
    .RegWrite(RegWrite), 
    .ALUOp(ALUOp),
    .J(J)
    );

ALUDecoder a(
    .op5(op[5]), 
    .funct3(funct3), 
    .funct75(funct75), 
    .ALUOp(ALUOp), 
    .ALUControl(ALUControl),
    .DataType(DataType)
    );

assign PCSrc = Zero & Branch;
    

    
endmodule
