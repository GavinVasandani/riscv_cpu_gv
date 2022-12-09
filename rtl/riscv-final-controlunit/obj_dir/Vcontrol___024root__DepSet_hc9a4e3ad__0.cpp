// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol.h for the primary calling header

#include "verilated.h"

#include "Vcontrol___024root.h"

extern const VlUnpacked<CData/*0:0*/, 128> Vcontrol__ConstPool__TABLE_h5989c065_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vcontrol__ConstPool__TABLE_h458a45bc_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcontrol__ConstPool__TABLE_h4d344348_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcontrol__ConstPool__TABLE_h7df60976_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcontrol__ConstPool__TABLE_h9cbb4b03_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcontrol__ConstPool__TABLE_h9c2b895f_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vcontrol__ConstPool__TABLE_h5d50d3bc_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vcontrol__ConstPool__TABLE_h3d416e20_0;
extern const VlUnpacked<CData/*3:0*/, 64> Vcontrol__ConstPool__TABLE_habb9cf20_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vcontrol__ConstPool__TABLE_hcec7b2ae_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vcontrol__ConstPool__TABLE_h5b095eca_0;

VL_INLINE_OPT void Vcontrol___024root___ico_sequent__TOP__0(Vcontrol___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    CData/*5:0*/ __Vtableidx2;
    // Body
    __Vtableidx1 = vlSelf->op;
    vlSelf->RegWrite = Vcontrol__ConstPool__TABLE_h5989c065_0
        [__Vtableidx1];
    vlSelf->ImmSrc = Vcontrol__ConstPool__TABLE_h458a45bc_0
        [__Vtableidx1];
    vlSelf->ALUSrc = Vcontrol__ConstPool__TABLE_h4d344348_0
        [__Vtableidx1];
    vlSelf->MemWrite = Vcontrol__ConstPool__TABLE_h7df60976_0
        [__Vtableidx1];
    vlSelf->ResultSrc = Vcontrol__ConstPool__TABLE_h9cbb4b03_0
        [__Vtableidx1];
    vlSelf->control__DOT__Branch = Vcontrol__ConstPool__TABLE_h9c2b895f_0
        [__Vtableidx1];
    vlSelf->control__DOT__ALUOp = Vcontrol__ConstPool__TABLE_h5d50d3bc_0
        [__Vtableidx1];
    vlSelf->J = Vcontrol__ConstPool__TABLE_h3d416e20_0
        [__Vtableidx1];
    vlSelf->PCSrc = ((IData)(vlSelf->Zero) & (IData)(vlSelf->control__DOT__Branch));
    __Vtableidx2 = (((IData)(vlSelf->funct75) << 5U) 
                    | (((IData)(vlSelf->funct3) << 2U) 
                       | (IData)(vlSelf->control__DOT__ALUOp)));
    vlSelf->ALUControl = Vcontrol__ConstPool__TABLE_habb9cf20_0
        [__Vtableidx2];
    if ((2U & Vcontrol__ConstPool__TABLE_hcec7b2ae_0
         [__Vtableidx2])) {
        vlSelf->DataType = Vcontrol__ConstPool__TABLE_h5b095eca_0
            [__Vtableidx2];
    }
}

void Vcontrol___024root___eval_ico(Vcontrol___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vcontrol___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vcontrol___024root___eval_act(Vcontrol___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root___eval_act\n"); );
}

void Vcontrol___024root___eval_nba(Vcontrol___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root___eval_nba\n"); );
}

void Vcontrol___024root___eval_triggers__ico(Vcontrol___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontrol___024root___dump_triggers__ico(Vcontrol___024root* vlSelf);
#endif  // VL_DEBUG
void Vcontrol___024root___eval_triggers__act(Vcontrol___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontrol___024root___dump_triggers__act(Vcontrol___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontrol___024root___dump_triggers__nba(Vcontrol___024root* vlSelf);
#endif  // VL_DEBUG

void Vcontrol___024root___eval(Vcontrol___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<0> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vcontrol___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if ((0x64U < vlSelf->__VicoIterCount)) {
#ifdef VL_DEBUG
                Vcontrol___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("control.sv", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vcontrol___024root___eval_ico(vlSelf);
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
            Vcontrol___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if ((0x64U < vlSelf->__VactIterCount)) {
#ifdef VL_DEBUG
                    Vcontrol___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("control.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vcontrol___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if ((0x64U < __VnbaIterCount)) {
#ifdef VL_DEBUG
                Vcontrol___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("control.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vcontrol___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vcontrol___024root___eval_debug_assertions(Vcontrol___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->op & 0x80U))) {
        Verilated::overWidthError("op");}
    if (VL_UNLIKELY((vlSelf->funct3 & 0xf8U))) {
        Verilated::overWidthError("funct3");}
    if (VL_UNLIKELY((vlSelf->funct75 & 0xfeU))) {
        Verilated::overWidthError("funct75");}
    if (VL_UNLIKELY((vlSelf->Zero & 0xfeU))) {
        Verilated::overWidthError("Zero");}
}
#endif  // VL_DEBUG
