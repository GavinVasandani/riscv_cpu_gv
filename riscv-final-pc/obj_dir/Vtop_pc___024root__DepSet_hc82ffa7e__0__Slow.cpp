// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_pc.h for the primary calling header

#include "verilated.h"

#include "Vtop_pc___024root.h"

VL_ATTR_COLD void Vtop_pc___024root___eval_static(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop_pc___024root___eval_initial__TOP(Vtop_pc___024root* vlSelf);

VL_ATTR_COLD void Vtop_pc___024root___eval_initial(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval_initial\n"); );
    // Body
    Vtop_pc___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vtop_pc___024root___eval_initial__TOP(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval_initial__TOP\n"); );
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

VL_ATTR_COLD void Vtop_pc___024root___eval_final(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop_pc___024root___eval_triggers__stl(Vtop_pc___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pc___024root___dump_triggers__stl(Vtop_pc___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop_pc___024root___eval_stl(Vtop_pc___024root* vlSelf);

VL_ATTR_COLD void Vtop_pc___024root___eval_settle(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop_pc___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if ((0x64U < vlSelf->__VstlIterCount)) {
#ifdef VL_DEBUG
                Vtop_pc___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("top_pc.sv", 4, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop_pc___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pc___024root___dump_triggers__stl(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_pc___024root___stl_sequent__TOP__0(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___stl_sequent__TOP__0\n"); );
    // Body
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

VL_ATTR_COLD void Vtop_pc___024root___eval_stl(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop_pc___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pc___024root___dump_triggers__ico(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pc___024root___dump_triggers__act(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pc___024root___dump_triggers__nba(Vtop_pc___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pc___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

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
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->top_pc__DOT__pcRom__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__VstlIterCount = 0;
    vlSelf->__VicoIterCount = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__VactIterCount = 0;
    vlSelf->__VactContinue = 0;
}
