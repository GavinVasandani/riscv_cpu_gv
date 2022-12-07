// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(trigger,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ top__DOT__RegWrite;
    CData/*0:0*/ top__DOT__ALUSrc;
    CData/*3:0*/ top__DOT__ALU_ctrl;
    CData/*0:0*/ top__DOT__EQ;
    CData/*1:0*/ top__DOT__DataType;
    CData/*0:0*/ top__DOT__J;
    CData/*1:0*/ top__DOT__ImmSrc;
    CData/*0:0*/ top__DOT__MemWrite;
    CData/*0:0*/ top__DOT__ResultSrc;
    CData/*0:0*/ top__DOT__control_unit__DOT__Branch;
    CData/*1:0*/ top__DOT__control_unit__DOT__ALUOp;
    CData/*7:0*/ top__DOT__ALU__DOT__ram1__DOT__byteAssign;
    CData/*0:0*/ __Vclklast__TOP__clk;
    SData/*15:0*/ top__DOT__ALU__DOT__ram1__DOT__halfwordAssign;
    VL_OUT(a0,31,0);
    IData/*31:0*/ top__DOT__PC_instr;
    IData/*31:0*/ top__DOT__ImmOp;
    IData/*31:0*/ top__DOT__myPC__DOT__PC;
    IData/*31:0*/ top__DOT__myPC__DOT__pcReg__DOT__next_PC;
    IData/*31:0*/ top__DOT__ALU__DOT__rd1;
    IData/*31:0*/ top__DOT__ALU__DOT__rd2;
    IData/*31:0*/ top__DOT__ALU__DOT__ALUOp2;
    IData/*31:0*/ top__DOT__ALU__DOT__ALUout;
    IData/*31:0*/ top__DOT__ALU__DOT__ReadData;
    VlUnpacked<CData/*7:0*/, 4096> top__DOT__myPC__DOT__pcRom__DOT__rom_array;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__ALU__DOT__regFile1__DOT__regFile_array;
    VlUnpacked<CData/*7:0*/, 2> top__DOT__ALU__DOT__ram1__DOT__ram_array;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
