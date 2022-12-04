module mainDecoder(
    input logic[6:0]    op,

    output logic[1:0]   ImmSrc,
    output logic        Branch,
    output logic        ResultSrc,
    output logic        MemWrite,
    output logic        ALUSrc,
    output logic        RegWrite,
    output logic[1:0]   ALUOp
);

always_comb begin
    case(op)
        7'b0000011: begin           //lw
            RegWrite = 1;
            ImmSrc = 2'b00;
            ALUSrc = 1;
            MemWrite = 0;
            ResultSrc = 1;
            Branch = 0;
            ALUOp = 2'b00;
        end

        7'b0100011: begin           //sw
            RegWrite = 0;
            ImmSrc = 2'b01;
            ALUSrc = 1;
            MemWrite = 1;
            //ResultSrc = 1;
            Branch = 0;
            ALUOp = 2'b00;
        end

        7'b0110011: begin           //R-type
            RegWrite = 1;
            //ImmSrc = 2'b00;
            ALUSrc = 0;
            MemWrite = 0;
            ResultSrc = 0;
            Branch = 0;
            ALUOp = 2'b10;
        end

        7'b1100011: begin           //beq
            RegWrite = 0;
            ImmSrc = 2'b10;
            ALUSrc = 0;
            MemWrite = 0;
            //ResultSrc = 1;
            Branch = 1;
            ALUOp = 2'b01;
        end
    endcase
end

endmodule
