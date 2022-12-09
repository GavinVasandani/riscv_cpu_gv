// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop_pc__Syms.h"
#include "Vtop_pc.h"
#include "Vtop_pc___024root.h"

// FUNCTIONS
Vtop_pc__Syms::~Vtop_pc__Syms()
{
}

Vtop_pc__Syms::Vtop_pc__Syms(VerilatedContext* contextp, const char* namep, Vtop_pc* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
