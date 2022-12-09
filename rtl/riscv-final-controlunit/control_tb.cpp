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
    top->funct3 = 0; 
    top->funct75 = 0xFFF;
    top->Zero = 1;

   
    for (i=0; i<300; i++){ 

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
