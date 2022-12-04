module sign_ext(
    input logic clk,
    input logic [31:0] inst,
    input logic ImmSrc,
    output logic [31:0] ImmOp,
    output logic [31:0] rem
);

    logic [11:0] imm_imm = inst[31:20];
    logic [12:0] imm_branch = {inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};

    assign rem = inst;

    always_ff @(posedge clk)
        if (ImmSrc) 
            ImmOp <= {{20{imm_imm[11]}}, imm_imm};

        else 
            ImmOp <= {{19{imm_branch[12]}}, imm_branch};

endmodule
