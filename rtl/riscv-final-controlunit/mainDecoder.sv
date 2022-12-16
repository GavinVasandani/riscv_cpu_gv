module mainDecoder(
    input logic[6:0]    op, // added by arnav

    output logic[2:0]   ImmSrc,
    output logic        Branch,
    output logic        ResultSrc,
    output logic        MemWrite,
    output logic        ALUSrc,
    output logic        RegWrite,
    output logic[1:0]   ALUOp,
    output logic[1:0]   J
);

always_comb begin
    case(op)
        7'b0000011: begin           // Load
            RegWrite = 1;
            ImmSrc = 3'b000;
            ALUSrc = 1;
            MemWrite = 0;
            ResultSrc = 1;
            Branch = 0;
            ALUOp = 2'b00;
            J = 2'b00;

        end

        7'b0100011: begin           //S-type
            RegWrite = 0;
            ImmSrc = 3'b001;
            ALUSrc = 1;
            MemWrite = 1;
            ResultSrc = 1'b0;
            Branch = 0;
            ALUOp = 2'b00;
            J = 2'b00;
        end

        7'b0010011: begin           //I-type
            RegWrite = 1;
            ImmSrc = 3'b000;
            ALUSrc = 1;
            MemWrite = 0;
            ResultSrc = 0;
            Branch = 0;
            ALUOp = 2'b10;
            J = 2'b00;
        end

        7'b0110111: begin // U-type
            RegWrite = 1;
            ImmSrc = 3'b100;
            ALUSrc = 1;
            MemWrite = 0;
            ResultSrc = 0;
            Branch = 0;
            ALUOp = 2'b11;
            J = 2'b00;
        end

        7'b0110011: begin           //R-type
            RegWrite = 1;
            ImmSrc = 3'bxx;
            ALUSrc = 0;
            MemWrite = 0;
            ResultSrc = 0;
            Branch = 0;
            ALUOp = 2'b10;
            J = 2'b00;
        end

        7'b1100011: begin           //B-type
            RegWrite = 0;
            ImmSrc = 3'b010;
            ALUSrc = 0;
            MemWrite = 0;
            ResultSrc = 1'bx;
            Branch = 1;
            ALUOp = 2'b01;
            J = 2'b00;
        end

        7'b1101111: begin           // JAL
            RegWrite = 1;
            ImmSrc = 3'b011;
            ALUSrc = 1'bx;
            MemWrite = 0;
            ResultSrc = 1'bx;
            Branch = 0;
            ALUOp = 2'bxx;
            J = 2'b01;
        end

        7'b1100111: begin           //JALR
            RegWrite = 1;
            ImmSrc = 3'b000; // same as I-type tbh, might change
            ALUSrc = 1'b1; // immediate
            MemWrite = 0; // only for l and s
            ResultSrc = 1'b0; // not from datamem
            Branch = 0; // not a branch
            ALUOp = 2'b10; // same as I-type tbh
            J = 2'b10; // used in PC block
        end

        default: begin
            RegWrite = 1'b0;
            ImmSrc = 3'bxx;
            ALUSrc = 1'bx;
            MemWrite = 1'b0;
            ResultSrc = 1'b0;
            Branch = 1'b0;
            ALUOp = 2'bxx;
            J = 2'b00;
        end
    endcase
end

endmodule
