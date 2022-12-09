module ext(
    input logic [31:7] imm, 
    input logic [2:0]  ImmSrc,
    output logic[31:0] ImmExt
);

    always_comb 
        case(ImmSrc)
            3'b000:                                            //Immediate
                ImmExt = {{20{imm[31]}}, imm[31:20]};
            
            3'b001:                                            //Store
                ImmExt = {{20{imm[31]}}, imm[31:25], imm[11:7]};

            3'b010:                                            //Branch
                ImmExt = {{19{imm[31]}}, imm[31],imm[7],imm[30:25],imm[11:8],1'b0};

            3'b011:                                            //JAL
                ImmExt = {{12{imm[31]}}, imm[19:12], imm[20], imm[30:21],1'b0};

            3'b100:                                            //JALR
                ImmExt = {{20{imm[31]}}, imm[31:20]};
            default: ImmExt = {{20{imm[31]}}, imm[31:20]};
        endcase

endmodule
