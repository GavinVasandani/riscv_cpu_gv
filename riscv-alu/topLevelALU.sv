module topLevelALU# (
    parameter 
              // NumberOfReg = 32,
              Address_Width_RegFile = 5, //32 registers so address size is 5 bits
              Address_Width_RAM = 17,
              Data_Width = 32
              //ALU_Instruction_Width = 10;
) (
//Interface Signals

    //Regfile signals
    input logic clk,
    input logic [Address_Width_RegFile-1:0] rs1, //32 registers so 5 bit address, rs1 is 1st source reg, arithmetic input
    input logic [Address_Width_RegFile-1:0] rs2, //rs2 is 2nd source reg, arithmetic input
    input logic [Address_Width_RegFile-1:0] rd, //rd is destination reg to store arithmetic output
    input logic regFileWen, //Enable to determine whether we can write to register file or not
    input logic trigger, 

    //ALU input mux signals
    input logic ALUSrc,
    input logic [Data_Width-1:0] ImmOp,

    //ALU signal
    input logic [3:0] ALU_ctrl,

    //RAM signals
    input logic MemWrite, //WE
    input logic [1:0] dataType,

    //ResultSrcMux signal
    input logic SrcSel, //select for ResultSrcMux

    //ResultPCMux signal
    input logic [Data_Width-1:0] newPC, //PC+4 input
    input logic JumpSel, //select for resultPCMux

    //Outputs
    output logic eq,
    output logic [Data_Width-1:0] a0
);

//Wires
    logic [Data_Width-1:0] rd1; //regfile output 1
    logic [Data_Width-1:0] rd2; //regfile output 2
    logic [Data_Width-1:0] ALUOp2; //ALU input 2
    logic [Data_Width-1:0] ALUout; //ALU output
    logic [Data_Width-1:0] ReadData; //RAM output
    logic [Data_Width-1:0] ResultSrcOutput; //ResultSrcMux output 
    logic [Data_Width-1:0] regWrite; //data to write to register

//Initializing objects of the different modules and linking them
//.variablefromClass(variablefromTop)
//regFile regFile1 (clk, rs1, rs2, rd, en, din, rd1, rd2, a0);
regfile regFile1 (
    .clk(clk),
    .rs1(rs1),
    .rs2(rs2), 
    .rd(rd), 
    .en(regFileWen), 
    .trigger(trigger),
    .din(regWrite), //register file input is regWrite
    .rd1(rd1), 
    .rd2(rd2),
    .a0(a0) //check if needed
);
//regFileMux mux1 (rd2, ImmOp, ALUSrc, ALUOp2);
regfileMux mux1 ( //Mux to determine ALU Op2
    .regOp2(rd2), 
    .ImmOp(ImmOp), 
    .ALUSrc(ALUSrc), 
    .ALUOp2(ALUOp2)
);
//regFileALU alu1 (rd1, ALUOp2, ALU_ctrl, ALUout, eq);
regfileALU alu1 (
    .op1(rd1), 
    .op2(ALUOp2), 
    .ALU_ctrl(ALU_ctrl), 
    .ALUout(ALUout), 
    .eq(eq)
);

ram ram1 ( /* this works, presumably when doing sw, the address stored in the register
that is used is such that when added with offset it gives an LS Byte so it corresponds to
beginning of a word. */
//need to add signals for WW (Write Word), RB (Read Byte)
    .clk(clk),
    .WE(MemWrite),
    .dataType(dataType),
    .A(ALUout[Address_Width_RAM-1:0]),
    .WD(rd2),
    .RD(ReadData)
);

resultSrcMux resultSrcMux1 (
    .ALUResult(ALUout),
    .ReadData(ReadData),
    .SrcSel(SrcSel), //ResultSrc select
    .OutputSrcMux(ResultSrcOutput) //previously Result
);

resultPCMux resultPCMux1 (
    .ResultSrc(ResultSrcOutput), //previously ALUResult
    .newPC(newPC),
    .JumpSel(JumpSel), //select
    .Result(regWrite)
);

endmodule
