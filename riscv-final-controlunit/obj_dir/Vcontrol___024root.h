// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcontrol.h for the primary calling header

#ifndef VERILATED_VCONTROL___024ROOT_H_
#define VERILATED_VCONTROL___024ROOT_H_  // guard

#include "verilated.h"

class Vcontrol__Syms;

class Vcontrol___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(op,6,0);
    VL_IN8(funct3,2,0);
    VL_IN8(funct75,0,0);
    VL_IN8(Zero,0,0);
    VL_OUT8(PCSrc,0,0);
    VL_OUT8(ResultSrc,0,0);
    VL_OUT8(MemWrite,0,0);
    VL_OUT8(ALUControl,3,0);
    VL_OUT8(ALUSrc,0,0);
    VL_OUT8(ImmSrc,1,0);
    VL_OUT8(RegWrite,0,0);
    VL_OUT8(DataType,1,0);
    VL_OUT8(J,0,0);
    CData/*0:0*/ control__DOT__Branch;
    CData/*1:0*/ control__DOT__ALUOp;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vcontrol__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcontrol___024root(Vcontrol__Syms* symsp, const char* name);
    ~Vcontrol___024root();
    VL_UNCOPYABLE(Vcontrol___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
