// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vext.h for the primary calling header

#include "verilated.h"

#include "Vext__Syms.h"
#include "Vext___024root.h"

void Vext___024root___ctor_var_reset(Vext___024root* vlSelf);

Vext___024root::Vext___024root(Vext__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vext___024root___ctor_var_reset(this);
}

void Vext___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vext___024root::~Vext___024root() {
}
