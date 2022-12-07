#include "VtopLevelALU.h" //class template to use is from VtopLevelALU.h
#include "verilated.h"
#include "verilated_vcd_c.h"


int main(int argc, char **argv, char **env) {
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    VtopLevelALU* top = new VtopLevelALU;
    //Create instance of class VtopLevelALU

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("topLevelALU.vcd"); //C++ executable of the system verilog file

    //Initial simulation inputs:
    //8 input logic:
    //test instruction 1: addi a1,a0,255 same as addi a1,zero,255 - works.
    /*top->clk = 1;
    top->rs1 = 0x0; //5 bit binary input so for a0 reg address is 00000
    top->rs2 = 0x3; //irrelevant for addi operation
    top->rd = 0x1; //a1 reg address
    top->regFileWen = 1;
    top->ALUSrc = 1; //as using we're immediate
    top->ImmOp = 0xFF; //which is 255
    top->ALU_ctrl = 0; //add operation so 0
    */

   //test instruction 2: bne a1, a0, xxxx - works.
   //expected output: eq = 1
   /*
    top->clk = 1;
    top->rs1 = 0x0; //5 bit binary input so for a0 reg address is 00000
    top->rs2 = 0x1; //5 bit binary input so for a1 reg address is 00001
    top->rd = 0x3; //not rewriting register value so don't care
    top->regFileWen = 0; //not rewriting register so 0
    top->ALUSrc = 0; //as we're using register value so 0
    top->ImmOp = 0xFF; //which is 255, don't care
    top->ALU_ctrl = 1; //bne operation so 1
    */

    //test instruction 3: lw a0, 0(a1) so a0 = mem[a1+0],
    //do lw a0, 1(a1) assign a0 = 1 initially, a1 = 0x01 so 0x01+1 = 0x02 and mem[0x02] assign 3
    //so expected a0 value is 3 - works.
    top->clk = 1;
    top->rs1 = 0x1; //a1 address given by rs1
    top->rs2 = 0x2; //not relevant aka don't care
    top->rd = 0x0; //write to a0
    top->regFileWen = 1; //as we're doing a0 = mem[a1+0]
    top->ALUSrc = 1; //we want to add immediate (offset) to rs1 to get effective address, assign 0 if adding value from 2 registers
    top->ImmOp = 0x1; //offset from base given by ImmOp, assumed ImmOp is after sign extension so its 32 bits
    top->ALU_ctrl = 0; //add operation
    top->MemWrite = 0; //Not rewriting mem location in RAM
    top->ResultSrc = 1; //ReadData is being assigned to register a0, if doing addi instruction then ResultSrc = 0

    for (i=0; i<300; i++){

        for (clk=0; clk<2; clk++){
            tfp->dump (2*i + clk);
            top->clk = !top->clk;
            top->eval();
        }  

        if (Verilated::gotFinish()) 
            exit(0);                // ... exit if finish OR 'q' pressed
        

    }
    tfp->close();
    exit(0);
}