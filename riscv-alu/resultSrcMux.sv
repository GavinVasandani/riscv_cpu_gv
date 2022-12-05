//Mux determining which result to send to regfile to write to register, either output from data memory or ALU output
module resultSrcMux #(
    parameter Data_Width = 32
) (
    //Interface signals
    input logic [Data_Width-1:0] ALUResult,
    input logic [Data_Width-1:0] ReadData,
    input logic ResultSrc,
    output logic [Data_Width-1:0] Result
);

assign Result = (ResultSrc) ? ReadData:ALUResult;
//so MuxSelect ? Output if mux select 1:Output if mux select 0

endmodule

