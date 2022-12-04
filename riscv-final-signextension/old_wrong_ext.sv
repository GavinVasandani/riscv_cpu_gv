module old_sign_ext (
    input clk,
    input logic [31:0] inst,
    input logic ImmSrc,
    output logic [31:0] ImmOp
);

    logic [11:0] imm;

    always_ff @(posedge clk)
        if (ImmSrc) 
        imm <= inst[31:20];

        else 
        imm <= {inst[31],inst[7],inst[30:25],inst[11:8]};
    


    assign ImmOp = {{20{imm[11]}}, imm[11:0]};


endmodule