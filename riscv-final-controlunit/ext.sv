module ext(
    input logic [31:7] imm,
    input logic [1:0]  ImmSrc,
    output logic[31:0] ImmExt
);

    always_comb 
        case(ImmSrc)
            2'b00:                                            //Immediate
                ImmExt = {{20{imm[31]}}, imm[31:20]};
            
            2'b01:                                            //Store
                ImmExt = {{20{imm[31]}}, imm[31:25], imm[11:7]};

            2'b10:                                            //Branch
                ImmExt = {{19{imm[31]}}, imm[31],imm[7],imm[30:25],imm[11:8],1'b0};

            2'b11:                                            //Jump
                ImmExt = {{13{imm[31]}}, imm[19:12], imm[20], imm[30:21]};
 
        endcase

endmodule
