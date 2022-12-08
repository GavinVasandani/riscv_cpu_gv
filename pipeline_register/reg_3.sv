module reg_3 # (
    parameter 
            Address_Width = 5, //32 registers so address size is 5 bits
            Data_Width = 32 //32-bit data
)(
    input logic         clk,
    input logic         RegWriteE,
    input logic [1:0]   ResultSrcE,
    input logic         MenWriteE,
    input logic [Address_Width-1:0] ALUResult,
    input logic [Data_Width-1:0]    WriteDataE,
    input logic [4:0]               RdE,
    input logic [Address_Width-1:0] PCPlus4E,

    output logic        RegWriteM,
    output logic [1:0]  ResultSrcM,
    output logic        MenWriteM,
    output logic [Address_Width-1:0] ALUResultM,
    output logic [Data_Width-1:0]    WriteDataM,
    output logic [4:0]               RdM,
    output logic  [Address_Width-1:0]PCPlus4M
);

always_ff @(posedge clk) begin
    RegWriteM <= RegWriteE;
    ResultSrcM <= ResultSrcE;
    MenWriteM <= MenWriteE;
    ALUResultM <= ALUResult;
    WriteDataM <= WriteDataE;
    RdM <= RdE;
    PCPlus4M <= PCPlus4E;
end


endmodule