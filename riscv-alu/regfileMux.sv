//Creating ALU Mux, so mux that decides op2 of ALU
//Now create top level design which connects regfile, mux, alu with wires

module regfileMux # (
    parameter Data_Width = 32

)(
    //Interface signals
    input logic [Data_Width-1:0] regOp2, //Output if mux select is 0
    input logic [Data_Width-1:0] ImmOp, //Output if mux select is 1
    input logic ALUSrc, //mux select
    output logic [Data_Width-1:0] ALUOp2 //2nd output of ALU
);

assign ALUOp2 = (ALUSrc) ? ImmOp:regOp2;

endmodule

