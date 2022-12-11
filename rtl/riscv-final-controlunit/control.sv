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
    output logic [2:0]  ImmSrc,
    output logic        RegWrite,
    output logic [1:0]  DataType,
    output logic [1:0]  J          //JAL if J == 01, JALR if J == 10
);

logic Zero_intermediate;
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

assign Zero_intermediate = funct3[0] ? !Zero : Zero;

assign PCSrc = (Zero_intermediate & Branch);
    

    
endmodule
