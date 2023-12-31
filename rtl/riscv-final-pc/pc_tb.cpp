#include "Vtop_pc.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
// #include "vbuddy.cpp" 

int main(int argc,char **argv, char **env){
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    //init top verilog instance 
    Vtop_pc* top = new Vtop_pc;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp= new VerilatedVcdC;
    top->trace (tfp,99);
    tfp->open ("top_pc.vcd");

    // init vbuddy
    // if (vbdOpen()!=1) return(-1);
    // vbdHeader("Counter");

    // initialize simulation inputs
    top->clk = 1;
    top->rst = 1;
    top->PCsrc = 0; // when in mode 0, the rom increments by 4. To test the ImmOp branch operation, set this to 1 and change the variable below to the increment/decrement you want to test.
    top->ImmOp = 0xFFF; // this should increment by -1 when in branch mode. It is greater than 8 bits and proves that the PC block works.
    
    // vbdSetMode(0);

    //run simulation for many clock cycles
    for (i=0; i<64; i++){ // clock cycles - used only 300 to limit size of VCD file
            //dump variables into VCD file and toggle clock
            for (clk=0; clk<2; clk++) {
                tfp->dump (2*i+clk);
                top->clk = !top->clk;
                top->eval();
            }
                
                // vbdHex(2, (int(top->instr) >> 4) & 0XF);
                // vbdHex(1, int(top->instr) & 0XF);

            // change input stimuli
            top->rst = (i % 11 == 0)&&(i>6)&&(i!=0);   // resets after every 12th clock cycle
            if (Verilated::gotFinish())  exit(0);
    }
    tfp->close();
    exit(0);

}
