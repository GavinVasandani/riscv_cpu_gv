module topLevelALU# (
    parameter 
              // NumberOfReg = 32,
              Address_Width_RegFile = 5, //32 registers so address size is 5 bits
              Data_Width = 32,
              CACHE_DATA_WIDTH = 41,
              BYTE_WIDTH = 8,
              RAM_ADDRESS_WIDTH = 16,
              CACHE_ADDRESS_WIDTH = 6
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
    input logic ALUSrc, //select
    input logic [Data_Width-1:0] ImmOp, //sign extended immediate input

    //ALU signal
    input logic [3:0] ALU_ctrl,

    //RAM signals
    input logic MemWrite, //WE (Write Enable)
    input logic [1:0] dataType, //00: word, 01: byte, 10: halfword

    //ResultSrcMux signal
    input logic SrcSel, //select for ResultSrcMux

    //ResultPCMux signal
    input logic [Data_Width-1:0] newPC, //PC+4 input
    input logic JumpSel, //select for resultPCMux

    //input logic flagInitial,

    //Outputs
    output logic eq,
    output logic [Data_Width-1:0] a0,
    output logic [Data_Width-1:0] RAM_array_value,
    output logic [CACHE_DATA_WIDTH-1:0] cache_array_value
    //output logic [Data_Width-1:0] Mux_RAM_array_value
);

//Wires
    logic [Data_Width-1:0] rd1; //regfile output 1
    logic [Data_Width-1:0] rd2; //regfile output 2
    logic [Data_Width-1:0] ALUOp2; //ALU input 2
    logic [Data_Width-1:0] ALUout; //ALU output
    //logic flagMiss;
    //logic [Data_Width-1:0] mainMemFetch; //data fetched from main mem when cache miss
    logic [Data_Width-1:0] ReadData; //RAM output
    logic [Data_Width-1:0] ResultSrcOutput; //ResultSrcMux output 
    logic [Data_Width-1:0] regWrite; //data to write to register
    //logic [BYTE_WIDTH-1:0] ram_array_wire_outer [2**RAM_ADDRESS_WIDTH-1:0];
    //logic [BYTE_WIDTH-1:0] ram_array_wire_inner [2**RAM_ADDRESS_WIDTH-1:0];
    //logic [CACHE_DATA_WIDTH-1:0] cache_array_wire_outer [2**CACHE_ADDRESS_WIDTH-1:0];
    //logic [CACHE_DATA_WIDTH-1:0] cache_array_wire_inner [2**CACHE_ADDRESS_WIDTH-1:0];
    //logic flagMiss_wire;

    //assign flagMiss = flagInitial; //initially flagMiss = flagInitial which = 0

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

ram_cache ramCache1 (
    .clk(clk),
    .A(ALUout),
    .WE(MemWrite),
    .WD(rd2),
    .dataType(dataType),
    .RD(ReadData),
    .RAM_array_value(RAM_array_value),
    .cache_array_value(cache_array_value)
);

/*
//This is all run simultaneously so it should be fine

data_cache cache1 (
    .clk(clk),
    .A(ALUout),
    .flagMissIn(flagMiss), //flagMiss is initially 0, maybe in tb assign flagMiss to 0
    .DataIn(mainMemFetch),
    .DataOut(ReadData),
    .flagMissOut(flagMiss) //flagMissOut is outputted to flagMiss wire which is inputted to flagMissIn
);

ram ram1 ( this works, presumably when doing sw, the address stored in the register
that is used is such that when added with offset it gives an LS Byte so it corresponds to
beginning of a word. 
//need to add signals for WW (Write Word), RB (Read Byte)
    .clk(clk),
    .WE(MemWrite),
    .dataType(dataType),
    .A(ALUout),
    .WD(rd2),
    .RD(ReadData)
);

if (flagMiss) begin //if flagMiss is 1 so must fetch value from main mem:

    //don't reinitialize just assign one wire value to another
    assign mainMemFetch = ReadData;

end
*/

/*
ram_cache_read ramCacheRead1 (
    .clk(clk),
    .A(ALUout),
    .ram_array(ram_array_wire_outer),
    .cache_array(cache_array_wire_outer),
    .RD(ReadData),
    .ram_arrayOut(ram_array_wire_inner),
    .cache_arrayOut(cache_array_wire_inner),
    .flagMiss(flagMiss_wire)
);

ram_cache_write ramCacheWrite1 (
    .clk(clk),
    .A(ALUout),
    .ram_array(ram_array_wire_inner),
    .cache_array(cache_array_wire_inner),
    .flagMiss(flagMiss_wire),
    .ram_arrayOut(ram_array_wire_outer),
    .cache_arrayOut(cache_array_wire_outer)
);
*/

resultSrcMux resultSrcMux1 (
    .ALUResult(ALUout),
    .ReadData(ReadData),
    .SrcSel(SrcSel), //ResultSrc select
    //.ram_array(ram_array_wire),
    .OutputSrcMux(ResultSrcOutput) //previously Result
    //.Mux_RAM_array_output(Mux_RAM_array_value)
);

resultPCMux resultPCMux1 (
    .ResultSrc(ResultSrcOutput), //previously ALUResult
    .newPC(newPC),
    .JumpSel(JumpSel), //select
    .Result(regWrite)
);

endmodule
