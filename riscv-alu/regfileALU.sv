//Creating ALU module
//ALU implements all ALU_controls
module regfileALU # (
    parameter //Address_Width = 5,
              //ALU_Instruction_Width = 1;
              Data_Width = 32 //Data_Width aka number of bits for instruction word doesn't need to correlate to size of main mem
) (
    //Interface signals
    input logic [Data_Width-1:0] op1, //input op1 into ALU which is output content from a register
    input logic [Data_Width-1:0] op2, //input op2 into ALU which is either 32-bit Imm or 32-bit content from register
    //input logic [ALU_Instruction_Width-1:0] ALU_ctrl,
    input logic [3:0] ALU_ctrl, //4 bit ALU_ctrl
    output logic [Data_Width-1:0] ALUout, //output of ALU is same size as ALU inputs
    output logic eq //Eq is probably carry out flag
);

//ALU is not clocked component, it's combinational so:

always_comb begin //ALU implements different arithmetic/logic based on opcode input
    case (ALU_ctrl) //ALU is combinational, async so normal = is fine for variable assignments
        4'b0000: begin//Add: //ALU implements add for lw and sw instructions also, the output operand is just used for something else
        //but that's irrelevant to ALU:
            ALUout = op1 + op2;
            eq = 0;
        end
        4'b0001: begin//Sub: //Used for beq, bne and sub instruction, eq output only used for 
            ALUout = op1 - op2; //order was determined from given instruction set/manual
            //determining eq:
            if((op1 - op2)==0) eq = 1; //can't do if(ALUout==0) as all logic is done simultaneously so ALUout isn't assigned op1-op2 when calling ALUout for this line.
            else eq = 0;
        end
        4'b0010: begin//AND instruction where we do bitwise AND, so compare (AND) bit at each position of op1 and op2 and output to that bit in rd
            ALUout = op1 & op2;
            //eq is don't care:
            eq = 0;
        end
        4'b0011: begin //OR instruction
            ALUout = op1 | op2;
            //eq is don't care:
            eq = 0;
        end
        4'b0101: begin //SLT and BLT instruction so compare operands and output 1 based on which is greater:
            //Setting rd = 1 (if rs1<rs2), rd = 0 (if rs1>rs2) so ALUout must be modified and ALUout written to rd: 
            if(op1 < op2) begin 
                //unsign extend ALUout:
                ALUout = 32'b1; //check if by default this is signed extended or it must go through sign extender
                //eq = 1 for BLT operation as op1 < op2:
                eq = 1;
            end
            else begin 
                ALUout = 32'b1;
                //eq = 0 for BLT operation as op1 > op2:
                eq = 0;
            end
        end
        4'b1000: begin //BGE instruction:
            if (op1 >= op2) eq = 1;
            else eq = 0;
            //ALUout is don't care
            ALUout = 32'b0;
        end
        //ALU_ctrl: 1'b100 shift left logical (SLL) operation also for SLLI where op2 is an immediate but that's assigned before entering ALU
        4'b0100: begin
            ALUout = op1 << op2;
            //eq is don't care:
            eq = 0;
        end
        //ALU_ctrl: 1'110 shift right logical (SRL) operation also for SRLI where op2 is an immediate but that's assigned before entering ALU
        4'b0110: begin
            ALUout = op1 >> op2;
            //eq is don't care:
            eq = 0;
        end
        4'b0111: begin //SRA instruction: so shift right and maintaining signed behaviour
            ALUout = op1 >>> op2;
            //eq is don't care:
            eq = 0;
        end
        4'b1001: begin //XOR instruction:
            ALUout = op1 ^ op2; 
            //eq is don't care:
            eq = 0;
        end
        default: begin
            ALUout = 0;
            eq = 0;
            $display("Instruction not detected.");
        end
    endcase
end
endmodule

