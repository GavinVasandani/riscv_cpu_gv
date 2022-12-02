// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_pc.h for the primary calling header

#include "verilated.h"

#include "Vtop_pc__Syms.h"
#include "Vtop_pc___024root.h"

void Vtop_pc___024root___ctor_var_reset(Vtop_pc___024root* vlSelf);

Vtop_pc___024root::Vtop_pc___024root(Vtop_pc__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_pc___024root___ctor_var_reset(this);
}

void Vtop_pc___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtop_pc___024root::~Vtop_pc___024root() {
}
