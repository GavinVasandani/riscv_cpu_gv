// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_pc.h for the primary calling header

#include "verilated.h"

#include "Vtop_pc___024root.h"

VL_INLINE_OPT void Vtop_pc___024root___ico_sequent__TOP__0(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->top_pc__DOT__pcReg__DOT__next_PC = ((IData)(vlSelf->PCsrc)
                                                 ? 
                                                (vlSelf->ImmOp 
                                                 + vlSelf->top_pc__DOT__PC)
                                                 : vlSelf->next_PC);
}

void Vtop_pc___024root___eval_ico(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop_pc___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop_pc___024root___eval_act(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop_pc___024root___nba_sequent__TOP__0(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->top_pc__DOT__PC = ((IData)(vlSelf->rst)
                                ? 0U : vlSelf->top_pc__DOT__pcReg__DOT__next_PC);
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
    vlSelf->next_PC = ((IData)(4U) + vlSelf->top_pc__DOT__PC);
    vlSelf->top_pc__DOT__pcReg__DOT__next_PC = ((IData)(vlSelf->PCsrc)
                                                 ? 
                                                (vlSelf->ImmOp 
                                                 + vlSelf->top_pc__DOT__PC)
                                                 : vlSelf->next_PC);
}

void Vtop_pc___024root___eval_nba(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop_pc___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtop_pc___024root___eval_triggers__ico(Vtop_pc___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pc___024root___dump_triggers__ico(Vtop_pc___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop_pc___024root___eval_triggers__act(Vtop_pc___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pc___024root___dump_triggers__act(Vtop_pc___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pc___024root___dump_triggers__nba(Vtop_pc___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_pc___024root___eval(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop_pc___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if ((0x64U < vlSelf->__VicoIterCount)) {
#ifdef VL_DEBUG
                Vtop_pc___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("top_pc.sv", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop_pc___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop_pc___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if ((0x64U < vlSelf->__VactIterCount)) {
#ifdef VL_DEBUG
                    Vtop_pc___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("top_pc.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop_pc___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if ((0x64U < __VnbaIterCount)) {
#ifdef VL_DEBUG
                Vtop_pc___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("top_pc.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop_pc___024root___eval_nba(vlSelf);
        }
    }
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
