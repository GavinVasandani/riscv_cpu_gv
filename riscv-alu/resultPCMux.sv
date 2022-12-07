//Mux that sends PC+4 to store in register if jump = 1, else send result
module resultPCMux #(
    parameter Data_Width = 32
) (
    //Interface signals
    input logic [Data_Width-1:0] ResultSrc,
    input logic [Data_Width-1:0] newPC,
    input logic JumpSel,
    output logic [Data_Width-1:0] Result
);

assign Result = (JumpSel) ? newPC:ResultSrc;
//so MuxSelect ? Output if mux select 1:Output if mux select 0

endmodule
