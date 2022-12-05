// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

extern const VlUnpacked<CData/*6:0*/, 128> Vtop__ConstPool__TABLE_h20d8e56b_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hc9fe864e_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_hf69f8455_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h4d3452f1_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h7df63985_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h9cbb3ab4_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h9c2b9990_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_h5d50a4ab_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hf2c0bf6e_0;
extern const VlUnpacked<CData/*2:0*/, 128> Vtop__ConstPool__TABLE_hf1416710_0;

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    CData/*6:0*/ __Vtableidx2;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0;
    CData/*7:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0;
    // Body
    __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0 = 0U;
    __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0 = 0U;
    if (vlSelf->top__DOT__MemWrite) {
        __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0 
            = vlSelf->top__DOT__ALU__DOT__rd2;
        __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0 
            = (0xffU & vlSelf->top__DOT__ALU__DOT__ALUout);
    }
    if (vlSelf->top__DOT__write_en) {
        __Vdlyvval__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0 
            = ((IData)(vlSelf->top__DOT__ResultSrc)
                ? vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
               [(0xffU & vlSelf->top__DOT__ALU__DOT__ALUout)]
                : vlSelf->top__DOT__ALU__DOT__ALUout);
        __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0 = 1U;
        __Vdlyvdim0__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0 
            = (0x1fU & (vlSelf->top__DOT__PC_instr 
                        >> 7U));
    }
    vlSelf->top__DOT__myPC__DOT__PC = ((IData)(vlSelf->rst)
                                        ? 0U : vlSelf->top__DOT__myPC__DOT__myPCreg__DOT__next_PC);
    if (__Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0) {
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0] 
            = __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0;
    }
    vlSelf->top__DOT__ALU__DOT__rd1 = vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array
        [(0x1fU & (vlSelf->top__DOT__PC_instr >> 0xfU))];
    vlSelf->top__DOT__ALU__DOT__rd2 = vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array
        [(0x1fU & (vlSelf->top__DOT__PC_instr >> 0x14U))];
    if (__Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0) {
        vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[__Vdlyvdim0__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0] 
            = __Vdlyvval__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0;
    }
    vlSelf->top__DOT__PC_instr = ((((0x1bU >= (0x1fU 
                                               & vlSelf->top__DOT__myPC__DOT__PC))
                                     ? vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array
                                    [(0x1fU & vlSelf->top__DOT__myPC__DOT__PC)]
                                     : 0U) << 0x18U) 
                                  | ((((0x1bU >= (0x1fU 
                                                  & ((IData)(1U) 
                                                     + vlSelf->top__DOT__myPC__DOT__PC)))
                                        ? vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array
                                       [(0x1fU & ((IData)(1U) 
                                                  + vlSelf->top__DOT__myPC__DOT__PC))]
                                        : 0U) << 0x10U) 
                                     | ((((0x1bU >= 
                                           (0x1fU & 
                                            ((IData)(2U) 
                                             + vlSelf->top__DOT__myPC__DOT__PC)))
                                           ? vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array
                                          [(0x1fU & 
                                            ((IData)(2U) 
                                             + vlSelf->top__DOT__myPC__DOT__PC))]
                                           : 0U) << 8U) 
                                        | ((0x1bU >= 
                                            (0x1fU 
                                             & ((IData)(3U) 
                                                + vlSelf->top__DOT__myPC__DOT__PC)))
                                            ? vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array
                                           [(0x1fU 
                                             & ((IData)(3U) 
                                                + vlSelf->top__DOT__myPC__DOT__PC))]
                                            : 0U))));
    __Vtableidx1 = (0x7fU & vlSelf->top__DOT__PC_instr);
    if ((1U & Vtop__ConstPool__TABLE_h20d8e56b_0[__Vtableidx1])) {
        vlSelf->top__DOT__write_en = Vtop__ConstPool__TABLE_hc9fe864e_0
            [__Vtableidx1];
    }
    if ((2U & Vtop__ConstPool__TABLE_h20d8e56b_0[__Vtableidx1])) {
        vlSelf->top__DOT__ImmSrc = Vtop__ConstPool__TABLE_hf69f8455_0
            [__Vtableidx1];
    }
    if ((4U & Vtop__ConstPool__TABLE_h20d8e56b_0[__Vtableidx1])) {
        vlSelf->top__DOT__ALUSrc = Vtop__ConstPool__TABLE_h4d3452f1_0
            [__Vtableidx1];
    }
    if ((8U & Vtop__ConstPool__TABLE_h20d8e56b_0[__Vtableidx1])) {
        vlSelf->top__DOT__MemWrite = Vtop__ConstPool__TABLE_h7df63985_0
            [__Vtableidx1];
    }
    if ((0x10U & Vtop__ConstPool__TABLE_h20d8e56b_0
         [__Vtableidx1])) {
        vlSelf->top__DOT__ResultSrc = Vtop__ConstPool__TABLE_h9cbb3ab4_0
            [__Vtableidx1];
    }
    if ((0x20U & Vtop__ConstPool__TABLE_h20d8e56b_0
         [__Vtableidx1])) {
        vlSelf->top__DOT__control_unit__DOT__Branch 
            = Vtop__ConstPool__TABLE_h9c2b9990_0[__Vtableidx1];
    }
    if ((0x40U & Vtop__ConstPool__TABLE_h20d8e56b_0
         [__Vtableidx1])) {
        vlSelf->top__DOT__control_unit__DOT__ALUOp 
            = Vtop__ConstPool__TABLE_h5d50a4ab_0[__Vtableidx1];
    }
    vlSelf->wr_en = vlSelf->top__DOT__write_en;
    vlSelf->alusrc = vlSelf->top__DOT__ALUSrc;
    __Vtableidx2 = ((0x40U & (vlSelf->top__DOT__PC_instr 
                              >> 0x18U)) | ((0x20U 
                                             & vlSelf->top__DOT__PC_instr) 
                                            | ((0x1cU 
                                                & (vlSelf->top__DOT__PC_instr 
                                                   >> 0xaU)) 
                                               | (IData)(vlSelf->top__DOT__control_unit__DOT__ALUOp))));
    if (Vtop__ConstPool__TABLE_hf2c0bf6e_0[__Vtableidx2]) {
        vlSelf->top__DOT__ALU_ctrl = Vtop__ConstPool__TABLE_hf1416710_0
            [__Vtableidx2];
    }
    vlSelf->top__DOT__ImmOp = ((2U & (IData)(vlSelf->top__DOT__ImmSrc))
                                ? ((1U & (IData)(vlSelf->top__DOT__ImmSrc))
                                    ? (((- (IData)(
                                                   (vlSelf->top__DOT__PC_instr 
                                                    >> 0x1fU))) 
                                        << 0x13U) | 
                                       ((0x7f800U & 
                                         (vlSelf->top__DOT__PC_instr 
                                          >> 1U)) | 
                                        ((0x400U & 
                                          (vlSelf->top__DOT__PC_instr 
                                           >> 0xaU)) 
                                         | (0x3ffU 
                                            & (vlSelf->top__DOT__PC_instr 
                                               >> 0x15U)))))
                                    : (((- (IData)(
                                                   (vlSelf->top__DOT__PC_instr 
                                                    >> 0x1fU))) 
                                        << 0xdU) | 
                                       ((0x1000U & 
                                         (vlSelf->top__DOT__PC_instr 
                                          >> 0x13U)) 
                                        | ((0x800U 
                                            & (vlSelf->top__DOT__PC_instr 
                                               << 4U)) 
                                           | ((0x7e0U 
                                               & (vlSelf->top__DOT__PC_instr 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlSelf->top__DOT__PC_instr 
                                                    >> 7U)))))))
                                : ((1U & (IData)(vlSelf->top__DOT__ImmSrc))
                                    ? (((- (IData)(
                                                   (vlSelf->top__DOT__PC_instr 
                                                    >> 0x1fU))) 
                                        << 0xcU) | 
                                       ((0xfe0U & (vlSelf->top__DOT__PC_instr 
                                                   >> 0x14U)) 
                                        | (0x1fU & 
                                           (vlSelf->top__DOT__PC_instr 
                                            >> 7U))))
                                    : (((- (IData)(
                                                   (vlSelf->top__DOT__PC_instr 
                                                    >> 0x1fU))) 
                                        << 0xcU) | 
                                       (vlSelf->top__DOT__PC_instr 
                                        >> 0x14U))));
    vlSelf->aluCtrl = vlSelf->top__DOT__ALU_ctrl;
    vlSelf->extout = vlSelf->top__DOT__ImmOp;
    vlSelf->top__DOT__ALU__DOT__ALUOp2 = ((IData)(vlSelf->top__DOT__ALUSrc)
                                           ? vlSelf->top__DOT__ImmOp
                                           : vlSelf->top__DOT__ALU__DOT__rd2);
    if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
        if (VL_LIKELY((1U & (IData)(vlSelf->top__DOT__ALU_ctrl)))) {
            vlSelf->top__DOT__ALU__DOT__ALUout = 0U;
            vlSelf->top__DOT__EQ = (0U == (vlSelf->top__DOT__ALU__DOT__rd1 
                                           - vlSelf->top__DOT__ALU__DOT__ALUOp2));
        } else {
            VL_WRITEF("Instruction not detected.\n");
        }
    } else {
        vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                              + vlSelf->top__DOT__ALU__DOT__ALUOp2);
        vlSelf->top__DOT__EQ = 0U;
    }
    vlSelf->Eq = vlSelf->top__DOT__EQ;
    vlSelf->top__DOT__myPC__DOT__myPCreg__DOT__next_PC 
        = (((IData)(vlSelf->top__DOT__EQ) & (IData)(vlSelf->top__DOT__control_unit__DOT__Branch))
            ? (vlSelf->top__DOT__myPC__DOT__PC + vlSelf->top__DOT__ImmOp)
            : ((IData)(4U) + vlSelf->top__DOT__myPC__DOT__PC));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
