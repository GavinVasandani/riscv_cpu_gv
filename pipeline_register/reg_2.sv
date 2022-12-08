module reg_2(
    input logic RegWriteD,
    input logic ResultSrcD,
    input logic MemWriteD,
    input logic JD,
    input logic BranchD,
    input logic ALUControlD,
    input logic ALUSrcD,
    
    input logic RD1D,
    input logic RD2D,
    input logic PCD,
    input logic RdD,
    input logic extD,
    input logic PCPlus4D,


    output logic RegWriteE,
    output logic ResultSrcE,
    output logic MemWriteE,
    output logic JE,
    output logic BranchE,
    output logic ALUControlE,
    output logic ALUSrcE,
    
    output logic RD1E,
    output logic RD2E,
    output logic PCE,
    output logic RdE,
    output logic extE,
    output logic PCPlus4E,
);

always_ff @(posedge clk) begin
    RegWriteE <= RegWriteD;
    ResultSrcE <= ResultSrcD;
    MemWriteE <= MemWriteD;
    JE <= JD;
    BranchE <= BranchD;
    ALUControlE <= ALUControlD;
    ALUSrcE <= ALUSrcD;

    RD1E <= RD1D;
    RD2E <= RD2D;
    PCE <= PCD;
    RdE <= RdD;
    extE <= extD;
    PCPlus4E <= PCPlus4D;
end

endmodule