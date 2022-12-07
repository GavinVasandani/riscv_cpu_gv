module mainDecoder(
    input logic[6:0]    op,

    output logic[1:0]   ImmSrc,
    output logic        Branch,
    output logic        ResultSrc,
    output logic        MemWrite,
    output logic        ALUSrc,
    output logic        RegWrite,
    output logic[1:0]   ALUOp,
    output logic        J
);

always_comb begin
    case(op)
        7'b0000011: begin           //LOAD
            RegWrite = 1;
            ImmSrc = 2'b00;
            ALUSrc = 1;
            MemWrite = 0;
            ResultSrc = 1;
            Branch = 0;
            ALUOp = 2'b00;
            J = 0;
        end

        7'b0100011: begin           //S-type
            RegWrite = 0;
            ImmSrc = 2'b01;
            ALUSrc = 1;
            MemWrite = 1;
            ResultSrc = 1'bx;
            Branch = 0;
            ALUOp = 2'b00;
            J = 0;
        end

        7'b0110011: begin           //R-type
            RegWrite = 1;
            ImmSrc = 2'bxx;
            ALUSrc = 0;
            MemWrite = 0;
            ResultSrc = 0;
            Branch = 0;
            ALUOp = 2'b10;
            J = 0;
        end

        7'b1100011: begin           //B-type
            RegWrite = 0;
            ImmSrc = 2'b10;
            ALUSrc = 0;
            MemWrite = 0;
            ResultSrc = 1'bx;
            Branch = 1;
            ALUOp = 2'b01;
            J = 0;
        end

        7'b1101111: begin           // Jump
            RegWrite = 1;
            ImmSrc = 2'b11;
            ALUSrc = 1'bx;
            MemWrite = 0;
            ResultSrc = 1'bx;
            Branch = 0;
            ALUOp = 2'bxx;
            J = 1;
        end
        default: begin
            RegWrite = 1'bx;
            ImmSrc = 2'bxx;
            ALUSrc = 1'bx;
            MemWrite = 1'bx;
            ResultSrc = 1'bx;
            Branch = 1'bx;
            ALUOp = 2'bxx;
            J = 1'bx;
        end
    endcase
end

endmodule
