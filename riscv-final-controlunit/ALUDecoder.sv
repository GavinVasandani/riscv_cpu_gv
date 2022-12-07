module ALUDecoder(
    input logic      op5,
    input logic[2:0] funct3,
    input logic      funct75,
    input logic[1:0] ALUOp,

    output logic[3:0] ALUControl
);

always_comb 

    case(ALUOp)
        2'b00: 
            ALUControl = 4'b0000;     //lw, sw
        2'b01:

            case(funct3)
                3'b000:
                    ALUControl = 4'b0001;     //beq
                
                3'b101:
                    ALUControl = 4'b1000;
            endcase

        2'b10:
            case(funct3) 
                3'b000:
                    if(funct75 == 1)                // sub
                        ALUControl = 4'b0001;
                    else                            // add
                        ALUControl = 4'b0000;

                3'b010:                             //slt
                    ALUControl = 4'b0101;
                
                3'b110:                             //or
                    ALUControl = 4'b0011;
                
                3'b111:                             //and
                    ALUControl = 4'b0010;           

                3'b001:                             //SLL
                    ALUControl = 4'b0100;

                3'b101:
                    if(funct75 == 0)                //SRL
                        ALUControl = 4'b0110;       
                    else                            //SRA
                        ALUControl = 4'b0110;       
                3'b100:                             //XOR
                    ALUControl = 4'b1001;
                
            endcase
    endcase
endmodule
