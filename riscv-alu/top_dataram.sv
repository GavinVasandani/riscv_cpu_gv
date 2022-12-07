module top_dataram #(
    parameter ADDRESS_WIDTH = 32,
    DATA_WIDTH = 32
)(
    input logic clk,
    input logic WE,
    input logic [1:0] dataType,
    input logic [ADDRESS_WIDTH-1:0] A,
    input logic [DATA_WIDTH-1:0] WD,
    input logic ResultSrc,
    output logic [DATA_WIDTH-1:0] Result
);

    logic [DATA_WIDTH-1:0] RD;

    ram dataram(clk, WE, dataType, A, WD, RD);

    assign Result = ResultSrc ? RD : A;

endmodule
