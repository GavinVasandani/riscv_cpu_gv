module topLevelALU# (
    parameter 
              // NumberOfReg = 32,
              Address_Width = 5, //32 registers so address size is 5 bits
              Data_Width = 32
              //ALU_Instruction_Width = 10;
) (
//Interface Signals
    input logic clk,
    input logic [Address_Width-1:0] rs1, //32 registers so 5 bit address, rs1 is 1st source reg, arithmetic input
    input logic [Address_Width-1:0] rs2, //rs2 is 2nd source reg, arithmetic input
    input logic [Address_Width-1:0] rd, //rd is destination reg to store arithmetic output
    input logic en, //Enable to determine whether we can write to register file or not
    //change: input logic [Data_Width-1:0] din, //Data in which takes in ALU output to write to register rd. Registers hold 32 bit word so din is 32 bits
    input logic ALUSrc,
    input logic [Data_Width-1:0] ImmOp,
    //input logic [ALU_Instruction_Width-1:0] ALU_ctrl;
    input logic [2:0] ALU_ctrl,
//Outputs
    //change: output logic [Data_Width-1:0] ALUout, //output of ALU is same size as ALU inputs
    output logic eq,
    output logic [Data_Width-1:0] a0
);

//Variable which acts in the middle:
logic [Data_Width-1:0] rd1;
logic [Data_Width-1:0] rd2;
logic [Data_Width-1:0] ALUOp2;

//Din is output of ALU and input of regfile:
logic [Data_Width-1:0] dinTest;

//Initializing objects of the different modules and linking them
//regFile regFile1 (clk, rs1, rs2, rd, en, din, rd1, rd2, a0);
regFile regFile1 (
    .clk(clk),
    .rs1(rs1),
    .rs2(rs2), 
    .rd(rd), 
    .en(en), 
    .din(dinTest), 
    .rd1(rd1), 
    .rd2(rd2),
    .a0(a0)
);
//regFileMux mux1 (rd2, ImmOp, ALUSrc, ALUOp2);
regFileMux mux1 (
    .regOp2(rd2), 
    .ImmOp(ImmOp), 
    .ALUSrc(ALUSrc), 
    .ALUOp2(ALUOp2)
);
//regFileALU alu1 (rd1, ALUOp2, ALU_ctrl, ALUout, eq);
regFileALU alu1 (
    .op1(rd1), 
    .op2(ALUOp2), 
    .ALU_ctrl(ALU_ctrl), 
    .ALUout(dinTest), 
    .eq(eq)
);

endmodule

