// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_pc.h for the primary calling header

#ifndef VERILATED_VTOP_PC___024ROOT_H_
#define VERILATED_VTOP_PC___024ROOT_H_  // guard

#include "verilated.h"

class Vtop_pc__Syms;

class Vtop_pc___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(PCsrc,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_IN(ImmOp,31,0);
    VL_OUT(instr,31,0);
    VL_OUT(next_PC,31,0);
    IData/*31:0*/ top_pc__DOT__PC;
    IData/*31:0*/ top_pc__DOT__pcReg__DOT__next_PC;
    VlUnpacked<CData/*7:0*/, 4096> top_pc__DOT__pcRom__DOT__rom_array;

    // INTERNAL VARIABLES
    Vtop_pc__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_pc___024root(Vtop_pc__Syms* symsp, const char* name);
    ~Vtop_pc___024root();
    VL_UNCOPYABLE(Vtop_pc___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
