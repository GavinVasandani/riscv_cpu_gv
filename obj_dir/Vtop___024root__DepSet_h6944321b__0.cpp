// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hff2d9170_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_h458a45bc_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hdbe7b003_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h7df60976_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h9cbb4b03_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h9c2b895f_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_h45fc93c4_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h3d416e20_0;
extern const VlUnpacked<CData/*3:0*/, 64> Vtop__ConstPool__TABLE_ha0243c93_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vtop__ConstPool__TABLE_hcec7b2ae_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vtop__ConstPool__TABLE_h5b095eca_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __VdfgTmp_h22bf108b__0;
    CData/*6:0*/ __Vtableidx1;
    CData/*5:0*/ __Vtableidx2;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v1;
    CData/*0:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v1;
    CData/*0:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v2;
    CData/*7:0*/ __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v2;
    CData/*0:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v3;
    CData/*7:0*/ __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v3;
    CData/*0:0*/ __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4;
    CData/*7:0*/ __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4;
    CData/*0:0*/ __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4;
    // Body
    __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0 = 0U;
    __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4 = 0U;
    __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0 = 0U;
    __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v1 = 0U;
    if (vlSelf->top__DOT__MemWrite) {
        if ((0U == (IData)(vlSelf->top__DOT__DataType))) {
            __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0 
                = (0xffU & vlSelf->top__DOT__ALU__DOT__rd2);
            __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0 = 1U;
            __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0 
                = (1U & ((IData)(1U) + vlSelf->top__DOT__ALU__DOT__ALUout));
            __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v1 
                = (0xffU & (vlSelf->top__DOT__ALU__DOT__rd2 
                            >> 8U));
            __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v1 
                = (1U & vlSelf->top__DOT__ALU__DOT__ALUout);
            __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v2 
                = (0xffU & (vlSelf->top__DOT__ALU__DOT__rd2 
                            >> 0x10U));
            __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v2 
                = (1U & ((IData)(1U) + vlSelf->top__DOT__ALU__DOT__ALUout));
            __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v3 
                = (vlSelf->top__DOT__ALU__DOT__rd2 
                   >> 0x18U);
            __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v3 
                = (1U & vlSelf->top__DOT__ALU__DOT__ALUout);
        } else {
            __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4 
                = (0xffU & vlSelf->top__DOT__ALU__DOT__rd2);
            __Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4 = 1U;
            __Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4 
                = (1U & ((IData)(1U) + vlSelf->top__DOT__ALU__DOT__ALUout));
        }
    }
    if (vlSelf->top__DOT__RegWrite) {
        if (VL_LIKELY((0U != (0x1fU & ((IData)(vlSelf->__VdfgTmp_h557ad426__0) 
                                       >> 7U))))) {
            __Vdlyvval__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0 
                = ((IData)(vlSelf->top__DOT__J) ? ((IData)(4U) 
                                                   + vlSelf->top__DOT__myPC__DOT__PC)
                    : ((IData)(vlSelf->top__DOT__ResultSrc)
                        ? vlSelf->top__DOT__ALU__DOT__ReadData
                        : vlSelf->top__DOT__ALU__DOT__ALUout));
            __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0 = 1U;
            __Vdlyvdim0__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0 
                = (0x1fU & ((IData)(vlSelf->__VdfgTmp_h557ad426__0) 
                            >> 7U));
        } else {
            VL_WRITEF("Cannot write to register 0.\n");
        }
    }
    if (vlSelf->trigger) {
        __Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v1 = 1U;
    }
    if (__Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0) {
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0] 
            = __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v0;
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v1] 
            = __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v1;
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v2] 
            = __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v2;
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v3] 
            = __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v3;
    }
    if (__Vdlyvset__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4) {
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vdlyvdim0__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4] 
            = __Vdlyvval__top__DOT__ALU__DOT__ram1__DOT__ram_array__v4;
    }
    if (__Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0) {
        vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[__Vdlyvdim0__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0] 
            = __Vdlyvval__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v0;
    }
    if (__Vdlyvset__top__DOT__ALU__DOT__regFile1__DOT__regFile_array__v1) {
        vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[0x11U] = 1U;
    }
    vlSelf->a0 = vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array
        [0xaU];
    vlSelf->top__DOT__myPC__DOT__PC = ((IData)(vlSelf->rst)
                                        ? 0U : vlSelf->top__DOT__myPC__DOT__pcReg__DOT__next_PC);
    __VdfgTmp_h22bf108b__0 = vlSelf->top__DOT__myPC__DOT__pcRom__DOT__rom_array
        [(0xfffU & ((IData)(2U) + vlSelf->top__DOT__myPC__DOT__PC))];
    vlSelf->__VdfgTmp_h22e24ab9__0 = vlSelf->top__DOT__myPC__DOT__pcRom__DOT__rom_array
        [(0xfffU & ((IData)(3U) + vlSelf->top__DOT__myPC__DOT__PC))];
    vlSelf->__VdfgTmp_h255a7f46__0 = vlSelf->top__DOT__myPC__DOT__pcRom__DOT__rom_array
        [(0xfffU & ((IData)(1U) + vlSelf->top__DOT__myPC__DOT__PC))];
    vlSelf->__VdfgTmp_h9436ee9b__0 = vlSelf->top__DOT__myPC__DOT__pcRom__DOT__rom_array
        [(0xfffU & vlSelf->top__DOT__myPC__DOT__PC)];
    vlSelf->top__DOT____Vcellinp__sign_extend__imm 
        = (((IData)(vlSelf->__VdfgTmp_h22e24ab9__0) 
            << 0x11U) | (((IData)(__VdfgTmp_h22bf108b__0) 
                          << 9U) | (((IData)(vlSelf->__VdfgTmp_h255a7f46__0) 
                                     << 1U) | (1U & 
                                               ((IData)(vlSelf->__VdfgTmp_h9436ee9b__0) 
                                                >> 7U)))));
    vlSelf->__VdfgTmp_h557ad426__0 = (((IData)(vlSelf->__VdfgTmp_h255a7f46__0) 
                                       << 8U) | (IData)(vlSelf->__VdfgTmp_h9436ee9b__0));
    __Vtableidx1 = (0x7fU & (IData)(vlSelf->__VdfgTmp_h9436ee9b__0));
    vlSelf->top__DOT__RegWrite = Vtop__ConstPool__TABLE_hff2d9170_0
        [__Vtableidx1];
    vlSelf->top__DOT__ImmSrc = Vtop__ConstPool__TABLE_h458a45bc_0
        [__Vtableidx1];
    vlSelf->top__DOT__ALUSrc = Vtop__ConstPool__TABLE_hdbe7b003_0
        [__Vtableidx1];
    vlSelf->top__DOT__MemWrite = Vtop__ConstPool__TABLE_h7df60976_0
        [__Vtableidx1];
    vlSelf->top__DOT__ResultSrc = Vtop__ConstPool__TABLE_h9cbb4b03_0
        [__Vtableidx1];
    vlSelf->top__DOT__control_unit__DOT__Branch = Vtop__ConstPool__TABLE_h9c2b895f_0
        [__Vtableidx1];
    vlSelf->top__DOT__control_unit__DOT__ALUOp = Vtop__ConstPool__TABLE_h45fc93c4_0
        [__Vtableidx1];
    vlSelf->top__DOT__J = Vtop__ConstPool__TABLE_h3d416e20_0
        [__Vtableidx1];
    vlSelf->__VdfgTmp_h899fe6da__0 = (((IData)(__VdfgTmp_h22bf108b__0) 
                                       << 0x10U) | (IData)(vlSelf->__VdfgTmp_h557ad426__0));
    vlSelf->top__DOT__ImmOp = ((2U & (IData)(vlSelf->top__DOT__ImmSrc))
                                ? ((1U & (IData)(vlSelf->top__DOT__ImmSrc))
                                    ? (((- (IData)(
                                                   (1U 
                                                    & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                       >> 0x18U)))) 
                                        << 0x13U) | 
                                       ((0x7f800U & 
                                         (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                          << 6U)) | 
                                        ((0x400U & 
                                          (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                           >> 3U)) 
                                         | (0x3ffU 
                                            & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                               >> 0xeU)))))
                                    : (((- (IData)(
                                                   (1U 
                                                    & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                       >> 0x18U)))) 
                                        << 0xdU) | 
                                       ((0x1000U & 
                                         (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                          >> 0xcU)) 
                                        | ((0x800U 
                                            & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                               << 0xbU)) 
                                           | ((0x7e0U 
                                               & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                  >> 0xdU)) 
                                              | (0x1eU 
                                                 & vlSelf->top__DOT____Vcellinp__sign_extend__imm))))))
                                : ((1U & (IData)(vlSelf->top__DOT__ImmSrc))
                                    ? (((- (IData)(
                                                   (1U 
                                                    & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                       >> 0x18U)))) 
                                        << 0xcU) | 
                                       ((0xfe0U & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                   >> 0xdU)) 
                                        | (0x1fU & vlSelf->top__DOT____Vcellinp__sign_extend__imm)))
                                    : (((- (IData)(
                                                   (1U 
                                                    & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                       >> 0x18U)))) 
                                        << 0xcU) | 
                                       (0xfffU & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                  >> 0xdU)))));
    __Vtableidx2 = ((0x20U & ((IData)(vlSelf->__VdfgTmp_h22e24ab9__0) 
                              >> 1U)) | ((0x1cU & ((IData)(vlSelf->__VdfgTmp_h255a7f46__0) 
                                                   >> 2U)) 
                                         | (IData)(vlSelf->top__DOT__control_unit__DOT__ALUOp)));
    vlSelf->top__DOT__ALU_ctrl = Vtop__ConstPool__TABLE_ha0243c93_0
        [__Vtableidx2];
    if ((2U & Vtop__ConstPool__TABLE_hcec7b2ae_0[__Vtableidx2])) {
        vlSelf->top__DOT__DataType = Vtop__ConstPool__TABLE_h5b095eca_0
            [__Vtableidx2];
    }
    vlSelf->top__DOT__ALU__DOT__rd1 = vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array
        [(0x1fU & (vlSelf->__VdfgTmp_h899fe6da__0 >> 0xfU))];
    vlSelf->top__DOT__ALU__DOT__rd2 = vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array
        [((0x10U & ((IData)(vlSelf->__VdfgTmp_h22e24ab9__0) 
                    << 4U)) | (0xfU & (vlSelf->__VdfgTmp_h899fe6da__0 
                                       >> 0x14U)))];
    vlSelf->top__DOT__ALU__DOT__ALUOp2 = ((IData)(vlSelf->top__DOT__ALUSrc)
                                           ? vlSelf->top__DOT__ImmOp
                                           : vlSelf->top__DOT__ALU__DOT__rd2);
    if ((8U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
        if (VL_UNLIKELY((4U & (IData)(vlSelf->top__DOT__ALU_ctrl)))) {
            vlSelf->top__DOT__ALU__DOT__ALUout = 0U;
            vlSelf->top__DOT__EQ = 0U;
            VL_WRITEF("Instruction not detected.\n");
        } else if (VL_UNLIKELY((2U & (IData)(vlSelf->top__DOT__ALU_ctrl)))) {
            VL_WRITEF("Instruction not detected.\n");
            vlSelf->top__DOT__ALU__DOT__ALUout = 0U;
            vlSelf->top__DOT__EQ = 0U;
        } else if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
            vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                                  ^ vlSelf->top__DOT__ALU__DOT__ALUOp2);
            vlSelf->top__DOT__EQ = 0U;
        } else {
            vlSelf->top__DOT__EQ = (vlSelf->top__DOT__ALU__DOT__rd1 
                                    >= vlSelf->top__DOT__ALU__DOT__ALUOp2);
            vlSelf->top__DOT__ALU__DOT__ALUout = 0U;
        }
    } else if ((4U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
        if ((2U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
            if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
                vlSelf->top__DOT__ALU__DOT__ALUout 
                    = ((0x1fU >= vlSelf->top__DOT__ALU__DOT__ALUOp2)
                        ? (vlSelf->top__DOT__ALU__DOT__rd1 
                           >> vlSelf->top__DOT__ALU__DOT__ALUOp2)
                        : 0U);
                vlSelf->top__DOT__EQ = 0U;
            } else {
                vlSelf->top__DOT__ALU__DOT__ALUout 
                    = ((0x1fU >= vlSelf->top__DOT__ALU__DOT__ALUOp2)
                        ? (vlSelf->top__DOT__ALU__DOT__rd1 
                           >> vlSelf->top__DOT__ALU__DOT__ALUOp2)
                        : 0U);
                vlSelf->top__DOT__EQ = 0U;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
            if ((vlSelf->top__DOT__ALU__DOT__rd1 < vlSelf->top__DOT__ALU__DOT__ALUOp2)) {
                vlSelf->top__DOT__ALU__DOT__ALUout = 1U;
                vlSelf->top__DOT__EQ = 1U;
            } else {
                vlSelf->top__DOT__ALU__DOT__ALUout = 1U;
                vlSelf->top__DOT__EQ = 0U;
            }
        } else {
            vlSelf->top__DOT__ALU__DOT__ALUout = ((0x1fU 
                                                   >= vlSelf->top__DOT__ALU__DOT__ALUOp2)
                                                   ? 
                                                  (vlSelf->top__DOT__ALU__DOT__rd1 
                                                   << vlSelf->top__DOT__ALU__DOT__ALUOp2)
                                                   : 0U);
            vlSelf->top__DOT__EQ = 0U;
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
        if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
            vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                                  | vlSelf->top__DOT__ALU__DOT__ALUOp2);
            vlSelf->top__DOT__EQ = 0U;
        } else {
            vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                                  & vlSelf->top__DOT__ALU__DOT__ALUOp2);
            vlSelf->top__DOT__EQ = 0U;
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
        vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                              - vlSelf->top__DOT__ALU__DOT__ALUOp2);
        vlSelf->top__DOT__EQ = (0U == (vlSelf->top__DOT__ALU__DOT__rd1 
                                       - vlSelf->top__DOT__ALU__DOT__ALUOp2));
    } else {
        vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                              + vlSelf->top__DOT__ALU__DOT__ALUOp2);
        vlSelf->top__DOT__EQ = 0U;
    }
    vlSelf->top__DOT__myPC__DOT__pcReg__DOT__next_PC 
        = ((((0x10U & (IData)(vlSelf->__VdfgTmp_h255a7f46__0))
              ? (~ (IData)(vlSelf->top__DOT__EQ)) : (IData)(vlSelf->top__DOT__EQ)) 
            & (IData)(vlSelf->top__DOT__control_unit__DOT__Branch))
            ? (vlSelf->top__DOT__ImmOp + vlSelf->top__DOT__myPC__DOT__PC)
            : ((IData)(4U) + vlSelf->top__DOT__myPC__DOT__PC));
    if ((0U == (IData)(vlSelf->top__DOT__DataType))) {
        vlSelf->top__DOT__ALU__DOT__ReadData = ((vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
                                                 [(1U 
                                                   & vlSelf->top__DOT__ALU__DOT__ALUout)] 
                                                 << 0x18U) 
                                                | ((vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
                                                    [
                                                    (1U 
                                                     & ((IData)(1U) 
                                                        + vlSelf->top__DOT__ALU__DOT__ALUout))] 
                                                    << 0x10U) 
                                                   | ((vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
                                                       [
                                                       (1U 
                                                        & vlSelf->top__DOT__ALU__DOT__ALUout)] 
                                                       << 8U) 
                                                      | vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
                                                      [
                                                      (1U 
                                                       & ((IData)(1U) 
                                                          + vlSelf->top__DOT__ALU__DOT__ALUout))])));
    } else if ((1U == (IData)(vlSelf->top__DOT__DataType))) {
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__byteAssign 
            = vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
            [(1U & ((IData)(1U) + vlSelf->top__DOT__ALU__DOT__ALUout))];
        vlSelf->top__DOT__ALU__DOT__ReadData = (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelf->top__DOT__ALU__DOT__ram1__DOT__byteAssign) 
                                                                >> 7U)))) 
                                                 << 8U) 
                                                | (IData)(vlSelf->top__DOT__ALU__DOT__ram1__DOT__byteAssign));
    } else if (VL_LIKELY((2U == (IData)(vlSelf->top__DOT__DataType)))) {
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__halfwordAssign 
            = ((vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
                [(1U & vlSelf->top__DOT__ALU__DOT__ALUout)] 
                << 8U) | vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array
               [(1U & ((IData)(1U) + vlSelf->top__DOT__ALU__DOT__ALUout))]);
        vlSelf->top__DOT__ALU__DOT__ReadData = (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelf->top__DOT__ALU__DOT__ram1__DOT__halfwordAssign) 
                                                                >> 0xfU)))) 
                                                 << 0x10U) 
                                                | (IData)(vlSelf->top__DOT__ALU__DOT__ram1__DOT__halfwordAssign));
    } else {
        VL_WRITEF("No dataType selected. Please choose word, byte or halfword.\n");
    }
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if ((0x64U < vlSelf->__VactIterCount)) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("top.sv", 16, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if ((0x64U < __VnbaIterCount)) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("top.sv", 16, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
