module reg_1(
    input logic clk,
    input logic instr,
    input logic PCF,
    input logic PCPlus4F,

    output logic instrD,
    output logic PCFo,
    output logic PCPlus4FD,
);

always_ff @(posedge clk) begin
    instrD <= instr;
    PCFD <= PCF;
    PCPlus4FD <= PCPlus4F;
end

endmodule
