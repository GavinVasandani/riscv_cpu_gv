// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<6>/*191:0*/ __Vtemp_h7a8db2f4__0;
    VlWide<5>/*159:0*/ __Vtemp_h83cfa321__0;
    // Body
    VL_WRITEF("Loading rom.\n");
    __Vtemp_h7a8db2f4__0[0U] = 0x2e686578U;
    __Vtemp_h7a8db2f4__0[1U] = 0x69762e73U;
    __Vtemp_h7a8db2f4__0[2U] = 0x636c6b64U;
    __Vtemp_h7a8db2f4__0[3U] = 0x726f672fU;
    __Vtemp_h7a8db2f4__0[4U] = 0x2f6d7970U;
    __Vtemp_h7a8db2f4__0[5U] = 0x737263U;
    VL_READMEM_N(true, 8, 4096, 0, VL_CVT_PACK_STR_NW(6, __Vtemp_h7a8db2f4__0)
                 ,  &(vlSelf->top__DOT__myPC__DOT__pcRom__DOT__rom_array)
                 , 0, ~0ULL);
    VL_WRITEF("Rom successfully loaded.\nInitializing regFile with null values (0).\n");
    __Vtemp_h83cfa321__0[0U] = 0x2e6d656dU;
    __Vtemp_h83cfa321__0[1U] = 0x70757473U;
    __Vtemp_h83cfa321__0[2U] = 0x6c65496eU;
    __Vtemp_h83cfa321__0[3U] = 0x65676669U;
    __Vtemp_h83cfa321__0[4U] = 0x72U;
    VL_READMEM_N(true, 32, 32, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_h83cfa321__0)
                 ,  &(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array)
                 , 0, ~0ULL);
    VL_WRITEF("Register successfully initialized\n");
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if ((0x64U < vlSelf->__VstlIterCount)) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("top.sv", 16, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h7189b1e2_0;
extern const VlUnpacked<CData/*2:0*/, 128> Vtop__ConstPool__TABLE_hf3e6b013_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h0378ea78_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h7df60976_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h9cbb4b03_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_h9c2b895f_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_h20c7ee4b_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_h12705e7b_0;
extern const VlUnpacked<CData/*3:0*/, 64> Vtop__ConstPool__TABLE_ha0243c93_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vtop__ConstPool__TABLE_hcec7b2ae_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vtop__ConstPool__TABLE_h5b095eca_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __VdfgTmp_h22bf108b__0;
    CData/*6:0*/ __Vtableidx1;
    CData/*5:0*/ __Vtableidx2;
    // Body
    vlSelf->a0 = vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array
        [0xaU];
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
    vlSelf->top__DOT__RegWrite = Vtop__ConstPool__TABLE_h7189b1e2_0
        [__Vtableidx1];
    vlSelf->top__DOT__ImmSrc = Vtop__ConstPool__TABLE_hf3e6b013_0
        [__Vtableidx1];
    vlSelf->top__DOT__ALUSrc = Vtop__ConstPool__TABLE_h0378ea78_0
        [__Vtableidx1];
    vlSelf->top__DOT__MemWrite = Vtop__ConstPool__TABLE_h7df60976_0
        [__Vtableidx1];
    vlSelf->top__DOT__ResultSrc = Vtop__ConstPool__TABLE_h9cbb4b03_0
        [__Vtableidx1];
    vlSelf->top__DOT__control_unit__DOT__Branch = Vtop__ConstPool__TABLE_h9c2b895f_0
        [__Vtableidx1];
    vlSelf->top__DOT__control_unit__DOT__ALUOp = Vtop__ConstPool__TABLE_h20c7ee4b_0
        [__Vtableidx1];
    vlSelf->top__DOT__J = Vtop__ConstPool__TABLE_h12705e7b_0
        [__Vtableidx1];
    vlSelf->__VdfgTmp_h899fe6da__0 = (((IData)(__VdfgTmp_h22bf108b__0) 
                                       << 0x10U) | (IData)(vlSelf->__VdfgTmp_h557ad426__0));
    vlSelf->top__DOT__ImmOp = ((4U & (IData)(vlSelf->top__DOT__ImmSrc))
                                ? ((2U & (IData)(vlSelf->top__DOT__ImmSrc))
                                    ? (((- (IData)(
                                                   (1U 
                                                    & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                       >> 0x18U)))) 
                                        << 0xcU) | 
                                       (0xfffU & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                  >> 0xdU)))
                                    : ((1U & (IData)(vlSelf->top__DOT__ImmSrc))
                                        ? (((- (IData)(
                                                       (1U 
                                                        & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                           >> 0x18U)))) 
                                            << 0xcU) 
                                           | (0xfffU 
                                              & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                 >> 0xdU)))
                                        : (((- (IData)(
                                                       (1U 
                                                        & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                           >> 0x18U)))) 
                                            << 0xcU) 
                                           | (0xfffU 
                                              & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                 >> 0xdU)))))
                                : ((2U & (IData)(vlSelf->top__DOT__ImmSrc))
                                    ? ((1U & (IData)(vlSelf->top__DOT__ImmSrc))
                                        ? (((- (IData)(
                                                       (1U 
                                                        & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                           >> 0x18U)))) 
                                            << 0x14U) 
                                           | ((0xff000U 
                                               & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                  << 7U)) 
                                              | ((0x800U 
                                                  & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                     >> 2U)) 
                                                 | (0x7feU 
                                                    & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                       >> 0xdU)))))
                                        : (((- (IData)(
                                                       (1U 
                                                        & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                           >> 0x18U)))) 
                                            << 0xdU) 
                                           | ((0x1000U 
                                               & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
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
                                            << 0xcU) 
                                           | ((0xfe0U 
                                               & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                  >> 0xdU)) 
                                              | (0x1fU 
                                                 & vlSelf->top__DOT____Vcellinp__sign_extend__imm)))
                                        : (((- (IData)(
                                                       (1U 
                                                        & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                           >> 0x18U)))) 
                                            << 0xcU) 
                                           | (0xfffU 
                                              & (vlSelf->top__DOT____Vcellinp__sign_extend__imm 
                                                 >> 0xdU))))));
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
            vlSelf->top__DOT__jalr_PC = 0U;
            VL_WRITEF("Instruction not detected.\n");
        } else if (VL_UNLIKELY((2U & (IData)(vlSelf->top__DOT__ALU_ctrl)))) {
            VL_WRITEF("Instruction not detected.\n");
            vlSelf->top__DOT__ALU__DOT__ALUout = 0U;
            vlSelf->top__DOT__EQ = 0U;
            vlSelf->top__DOT__jalr_PC = 0U;
        } else if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
            vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                                  ^ vlSelf->top__DOT__ALU__DOT__ALUOp2);
            vlSelf->top__DOT__EQ = 0U;
            vlSelf->top__DOT__jalr_PC = 0U;
        } else {
            vlSelf->top__DOT__EQ = (vlSelf->top__DOT__ALU__DOT__rd1 
                                    >= vlSelf->top__DOT__ALU__DOT__ALUOp2);
            vlSelf->top__DOT__ALU__DOT__ALUout = 0U;
            vlSelf->top__DOT__jalr_PC = 0U;
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
                vlSelf->top__DOT__jalr_PC = 0U;
            } else {
                vlSelf->top__DOT__ALU__DOT__ALUout 
                    = ((0x1fU >= vlSelf->top__DOT__ALU__DOT__ALUOp2)
                        ? (vlSelf->top__DOT__ALU__DOT__rd1 
                           >> vlSelf->top__DOT__ALU__DOT__ALUOp2)
                        : 0U);
                vlSelf->top__DOT__EQ = 0U;
                vlSelf->top__DOT__jalr_PC = 0U;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
            vlSelf->top__DOT__jalr_PC = 0U;
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
            vlSelf->top__DOT__jalr_PC = 0U;
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
        if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
            vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                                  | vlSelf->top__DOT__ALU__DOT__ALUOp2);
            vlSelf->top__DOT__jalr_PC = 0U;
            vlSelf->top__DOT__EQ = 0U;
        } else {
            vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                                  & vlSelf->top__DOT__ALU__DOT__ALUOp2);
            vlSelf->top__DOT__jalr_PC = 0U;
            vlSelf->top__DOT__EQ = 0U;
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__ALU_ctrl))) {
        vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                              - vlSelf->top__DOT__ALU__DOT__ALUOp2);
        vlSelf->top__DOT__jalr_PC = 0U;
        vlSelf->top__DOT__EQ = (0U == (vlSelf->top__DOT__ALU__DOT__rd1 
                                       - vlSelf->top__DOT__ALU__DOT__ALUOp2));
    } else {
        vlSelf->top__DOT__ALU__DOT__ALUout = (vlSelf->top__DOT__ALU__DOT__rd1 
                                              + vlSelf->top__DOT__ALU__DOT__ALUOp2);
        vlSelf->top__DOT__EQ = 0U;
        vlSelf->top__DOT__jalr_PC = (vlSelf->top__DOT__ALU__DOT__rd1 
                                     + vlSelf->top__DOT__ALU__DOT__ALUOp2);
    }
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
    vlSelf->top__DOT__myPC__DOT__pcReg__DOT__next_PC 
        = ((2U & (IData)(vlSelf->top__DOT__J)) ? vlSelf->top__DOT__jalr_PC
            : ((1U & ((((0x10U & (IData)(vlSelf->__VdfgTmp_h255a7f46__0))
                         ? (~ (IData)(vlSelf->top__DOT__EQ))
                         : (IData)(vlSelf->top__DOT__EQ)) 
                       & (IData)(vlSelf->top__DOT__control_unit__DOT__Branch)) 
                      | (IData)(vlSelf->top__DOT__J)))
                ? (vlSelf->top__DOT__ImmOp + vlSelf->top__DOT__myPC__DOT__PC)
                : ((IData)(4U) + vlSelf->top__DOT__myPC__DOT__PC)));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->trigger = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->a0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RegWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALUSrc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALU_ctrl = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__EQ = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__DataType = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__J = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ImmOp = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__jalr_PC = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ImmSrc = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__MemWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ResultSrc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____Vcellinp__sign_extend__imm = VL_RAND_RESET_I(25);
    vlSelf->top__DOT__myPC__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__myPC__DOT__pcReg__DOT__next_PC = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->top__DOT__myPC__DOT__pcRom__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__control_unit__DOT__Branch = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__control_unit__DOT__ALUOp = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ALU__DOT__rd1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALU__DOT__rd2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALU__DOT__ALUOp2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALU__DOT__ALUout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALU__DOT__ReadData = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__ALU__DOT__ram1__DOT__byteAssign = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__ALU__DOT__ram1__DOT__halfwordAssign = VL_RAND_RESET_I(16);
    vlSelf->__VdfgTmp_h22e24ab9__0 = 0;
    vlSelf->__VdfgTmp_h899fe6da__0 = 0;
    vlSelf->__VdfgTmp_h557ad426__0 = 0;
    vlSelf->__VdfgTmp_h255a7f46__0 = 0;
    vlSelf->__VdfgTmp_h9436ee9b__0 = 0;
    vlSelf->__VstlIterCount = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__VactIterCount = 0;
    vlSelf->__VactContinue = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
