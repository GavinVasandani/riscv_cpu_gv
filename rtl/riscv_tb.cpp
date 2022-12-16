#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp" 


int main(int argc, char **argv, char **env) {
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    Vtop* top = new Vtop;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("top.vcd");

    if (vbdOpen()!=1) return(-1);
    vbdHeader("Cache branch");

    top->trigger = 0;
    top->rst = 1;
    top->clk = 1;

    // vbdSetMode(1);

    for (i=0; i<2000000; i++){
        
        for (clk=0; clk<2; clk++){
            tfp->dump (2*i + clk);
            top->clk = !top->clk;
            top->eval();
        }   

        // vbdHex(4, (int(top->delay) >> 12) & 0XF); 
        // vbdHex(3, (int(top->delay) >> 8) & 0XF);
        // vbdHex(2, (int(top->delay) >> 4) & 0XF);
        // vbdHex(1, int(top->delay) & 0XF);

        // vbdHex(4, (int(top->a0) >> 12) & 0XF); 
        // vbdHex(3, (int(top->a0) >> 8) & 0XF);
        // vbdHex(2, (int(top->a0) >> 4) & 0XF);
        // vbdHex(1, int(top->a0) & 0XF);

        // vbdBar(top->a0 & 0xFF);

        // to see what the value of the delay would be, you can uncomment the line above, it would increase the latency and slow down the progression of the program.

        if (i>800000){
            vbdPlot(int(top->a0), 0, 255);
        }

        // vbdCycle(i+1);

        top->trigger = 0;
        top->rst = false;

        if (Verilated::gotFinish()) 
            exit(0);                // ... exit if finish OR 'q' pressed
    }
    tfp->close();
    exit(0);
}



