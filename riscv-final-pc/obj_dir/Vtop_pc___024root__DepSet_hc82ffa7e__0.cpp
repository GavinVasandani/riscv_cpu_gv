// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_pc.h for the primary calling header

#include "verilated.h"

#include "Vtop_pc___024root.h"

VL_INLINE_OPT void Vtop_pc___024root___sequent__TOP__0(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->top_pc__DOT__PC = ((IData)(vlSelf->rst)
                                ? 0U : vlSelf->top_pc__DOT__pcReg__DOT__next_PC);
    vlSelf->next_PC = ((IData)(4U) + vlSelf->top_pc__DOT__PC);
    vlSelf->instr = ((vlSelf->top_pc__DOT__pcRom__DOT__rom_array
                      [(0xfffU & ((IData)(3U) + vlSelf->top_pc__DOT__PC))] 
                      << 0x18U) | ((vlSelf->top_pc__DOT__pcRom__DOT__rom_array
                                    [(0xfffU & ((IData)(2U) 
                                                + vlSelf->top_pc__DOT__PC))] 
                                    << 0x10U) | ((vlSelf->top_pc__DOT__pcRom__DOT__rom_array
                                                  [
                                                  (0xfffU 
                                                   & ((IData)(1U) 
                                                      + vlSelf->top_pc__DOT__PC))] 
                                                  << 8U) 
                                                 | vlSelf->top_pc__DOT__pcRom__DOT__rom_array
                                                 [(0xfffU 
                                                   & vlSelf->top_pc__DOT__PC)])));
}

VL_INLINE_OPT void Vtop_pc___024root___combo__TOP__0(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->top_pc__DOT__pcReg__DOT__next_PC = ((IData)(vlSelf->PCsrc)
                                                 ? 
                                                (vlSelf->top_pc__DOT__PC 
                                                 + vlSelf->ImmOp)
                                                 : 
                                                ((IData)(4U) 
                                                 + vlSelf->top_pc__DOT__PC));
}

void Vtop_pc___024root___eval(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop_pc___024root___sequent__TOP__0(vlSelf);
    }
    Vtop_pc___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vtop_pc___024root___eval_debug_assertions(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->PCsrc & 0xfeU))) {
        Verilated::overWidthError("PCsrc");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
