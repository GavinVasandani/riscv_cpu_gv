// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vext.h for the primary calling header

#ifndef VERILATED_VEXT___024ROOT_H_
#define VERILATED_VEXT___024ROOT_H_  // guard

#include "verilated.h"

class Vext__Syms;

class Vext___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(ImmSrc,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    SData/*12:0*/ sign_ext__DOT__imm_branch;
    VL_IN(inst,31,0);
    VL_OUT(ImmOp,31,0);
    VL_OUT(rem,31,0);
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vext__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vext___024root(Vext__Syms* symsp, const char* name);
    ~Vext___024root();
    VL_UNCOPYABLE(Vext___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
