#include "Vcontrol.h"
#include "verilated.h"
#include "verilated_vcd_c.h" 

int main(int argc,char **argv, char **env){
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    Vcontrol* top = new Vcontrol;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp= new VerilatedVcdC;
    top->trace (tfp,99);
    tfp->open ("control.vcd");

    top->clk = 1;
    top->op = 1;
    top->funct3 = 0; // when in mode 0, the rom increments by 4. To test the ImmOp branch operation, set this to 1 and change the variable below to the increment/decrement you want to test.
    top->funct75 = 0xFFF; // this should increment by -1 when in branch mode. It is greater than 8 bits and proves that the PC block works.
    top->Zero = 1;

    //run simulation for many clock cycles
    for (i=0; i<300; i++){ // clock cycles - used only 300 to limit size of VCD file
            //dump variables into VCD file and toggle clock
            for (clk=0; clk<2; clk++) {
                tfp->dump (2*i+clk);
                top->clk = !top->clk;
                top->eval();
            }
            if (Verilated::gotFinish())  exit(0);
    }
    tfp->close();
    exit(0);

}
