module reg_4 # (
    parameter 
            Address_Width = 5, //32 registers so address size is 5 bits
            Data_Width = 32 //32-bit data
)(
    input logic         clk,
    input logic         RegWriteM,
    input logic [1:0]   ResultSrcM,   
    input logic [Address_Width-1:0] ALUResultM,
    input logic [Data_Width-1:0]    ReadData,
    input logic [4:0]               RdM,
    input logic [Address_Width-1:0] PCPlus4M,

    output logic        RegWriteW,
    output logic [1:0]  ResultSrcW,
    output logic [Address_Width-1:0] ALUResultW,
    output logic [Data_Width-1:0]    ReadDataW,
    output logic [4:0]               RdW,
    output logic [Address_Width-1:0] PCPlus4W
);

always_ff @(posedge clk) begin
    RegWriteW <= RegWriteM;
    ResultSrcW <= ResultSrcM;
    ALUResultW <= ALUResultM;
    ReadData <= ReadDataW;
    RdW <= RdM;
    PCPlus4W <= PCPlus4M;
end


endmodule