module ALUDecoder(
    input logic      op5,
    input logic[2:0] funct3,
    input logic      funct75,
    input logic[1:0] ALUOp,

    output logic[2:0] ALUControl
);

always_comb 

    case(ALUOp)
        2'b00: 
            ALUControl = 3'b000;     //lw, sw
        2'b01:  
            ALUControl = 3'b001;     //beq
        2'b10:
            case(funct3) 
                3'b000:
                    if({op5, funct75} == 2'b11)         // sub
                        ALUControl = 3'b001;
                    else                            // add
                        ALUControl = 3'b000;

                3'b010:                             //slt
                    ALUControl = 3'b101;
                
                3'b110:                             //or
                    ALUControl = 3'b011;
                
                3'b111:                             //and
                    ALUControl = 3'b010;
            
            endcase
    endcase
endmodule
