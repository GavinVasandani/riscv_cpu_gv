module ALUDecoder(
    input logic    op5, // added by arnav
    input logic[2:0] funct3,
    input logic      funct75,
    input logic[1:0] ALUOp,

    output logic[3:0] ALUControl,
    output logic[1:0] DataType
);

always_comb begin

    case(ALUOp)
        2'b00: begin
            ALUControl = 4'b0000;             //LOAD / STORE
            case (op5)
            1: begin
                case(funct3)
                    3'b010: begin                       //lw
                        DataType = 2'b00;
                    end
                    3'b100: begin                      //lbu
                        DataType = 2'b01;
                    end
                    3'b101: begin                      //lhu
                        DataType = 2'b10;
                    end
                    default: begin
                        DataType = 2'b01;
                    end
                endcase
            end
            0: begin
                case(funct3)
                    3'b010: begin                       //sw
                        DataType = 2'b00;
                    end
                    3'b000: begin                      //sb
                        DataType = 2'b01;
                    end
                    3'b001: begin                      //sh
                        DataType = 2'b10;
                    end
                    default: begin
                        DataType = 2'b01;
                    end
                endcase
            end
            endcase
        
        end
        2'b01: begin 

            case(funct3)
                3'b000:
                    ALUControl = 4'b0001;     //beq
                
                3'b101:
                    ALUControl = 4'b1000;
                default: begin
                    ALUControl = 4'b0001;
                end
            endcase
        end
        2'b10: begin
            case(funct3) 
                3'b000:
                    if((funct75 == 1)&&(op5 == 1))                // sub - there was a bug here, op5 fixed it
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
                default: begin
                    ALUControl = 4'b0000; // i believe this is the case only for jalr
                end
            endcase
        end
        2'b11: ALUControl = 4'b1111;
    endcase
end
endmodule
