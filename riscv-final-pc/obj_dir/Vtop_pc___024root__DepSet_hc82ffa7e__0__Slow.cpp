// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_pc.h for the primary calling header

#include "verilated.h"

#include "Vtop_pc___024root.h"

VL_ATTR_COLD void Vtop_pc___024root___initial__TOP__0(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___initial__TOP__0\n"); );
    // Init
    VlWide<6>/*191:0*/ __Vtemp_hfbf7ff78__0;
    // Body
    VL_WRITEF("Loading rom.\n");
    __Vtemp_hfbf7ff78__0[0U] = 0x2e686578U;
    __Vtemp_hfbf7ff78__0[1U] = 0x65722e73U;
    __Vtemp_hfbf7ff78__0[2U] = 0x6f756e74U;
    __Vtemp_hfbf7ff78__0[3U] = 0x6f672f63U;
    __Vtemp_hfbf7ff78__0[4U] = 0x6d797072U;
    __Vtemp_hfbf7ff78__0[5U] = 0x7372632fU;
    VL_READMEM_N(true, 8, 4096, 0, VL_CVT_PACK_STR_NW(6, __Vtemp_hfbf7ff78__0)
                 ,  &(vlSelf->top_pc__DOT__pcRom__DOT__rom_array)
                 , 0, ~0ULL);
    VL_WRITEF("Rom successfully loaded.\n");
}

VL_ATTR_COLD void Vtop_pc___024root___settle__TOP__0(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->next_PC = ((IData)(4U) + vlSelf->top_pc__DOT__PC);
    vlSelf->top_pc__DOT__pcReg__DOT__next_PC = ((IData)(vlSelf->PCsrc)
                                                 ? 
                                                (vlSelf->top_pc__DOT__PC 
                                                 + vlSelf->ImmOp)
                                                 : 
                                                ((IData)(4U) 
                                                 + vlSelf->top_pc__DOT__PC));
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

VL_ATTR_COLD void Vtop_pc___024root___eval_initial(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval_initial\n"); );
    // Body
    Vtop_pc___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vtop_pc___024root___eval_settle(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval_settle\n"); );
    // Body
    Vtop_pc___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vtop_pc___024root___final(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___final\n"); );
}

VL_ATTR_COLD void Vtop_pc___024root___ctor_var_reset(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->ImmOp = VL_RAND_RESET_I(32);
    vlSelf->PCsrc = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->instr = VL_RAND_RESET_I(32);
    vlSelf->next_PC = VL_RAND_RESET_I(32);
    vlSelf->top_pc__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->top_pc__DOT__pcReg__DOT__next_PC = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->top_pc__DOT__pcRom__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }
}
