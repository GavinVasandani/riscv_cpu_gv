module ALUDecoder(
    input logic[6:0]    op, // added by arnav
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
            case(funct3)
                3'b010:                       //WORD
                    DataType = 2'b00;
                3'b100:                       //BYTE UNSIGNED
                    DataType = 2'b01;
                3'b101:                       //HALF WORD UNSIGNED
                    DataType = 2'b10;
                default: begin
                    DataType = 2'b00;
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
                    if((funct75 == 1)&&(op == 7'b0110011))                // sub - there is a mistake here, which is causing a bug. Have to fix this after testing; hopeully fixed
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
