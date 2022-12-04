// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vext.h for the primary calling header

#include "verilated.h"

#include "Vext___024root.h"

VL_INLINE_OPT void Vext___024root___combo__TOP__0(Vext___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vext__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vext___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->rem = vlSelf->inst;
}

VL_INLINE_OPT void Vext___024root___sequent__TOP__0(Vext___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vext__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vext___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->ImmOp = ((IData)(vlSelf->ImmSrc) ? (((- (IData)(
                                                            (vlSelf->inst 
                                                             >> 0x1fU))) 
                                                 << 0xcU) 
                                                | (vlSelf->inst 
                                                   >> 0x14U))
                      : (((- (IData)((1U & ((IData)(vlSelf->sign_ext__DOT__imm_branch) 
                                            >> 0xcU)))) 
                          << 0xdU) | (IData)(vlSelf->sign_ext__DOT__imm_branch)));
}

void Vext___024root___eval(Vext___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vext__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vext___024root___eval\n"); );
    // Body
    Vext___024root___combo__TOP__0(vlSelf);
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vext___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vext___024root___eval_debug_assertions(Vext___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vext__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vext___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->ImmSrc & 0xfeU))) {
        Verilated::overWidthError("ImmSrc");}
}
#endif  // VL_DEBUG
