// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___initial__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___initial__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_he8d6983c__0;
    VlWide<4>/*127:0*/ __Vtemp_hcba095ea__0;
    VlWide<5>/*159:0*/ __Vtemp_h83cfa321__0;
    // Body
    VL_WRITEF("Loading rom.\n");
    __Vtemp_he8d6983c__0[0U] = 0x2e6d656dU;
    __Vtemp_he8d6983c__0[1U] = 0x696f6e73U;
    __Vtemp_he8d6983c__0[2U] = 0x72756374U;
    __Vtemp_he8d6983c__0[3U] = 0x696e7374U;
    VL_READMEM_N(true, 8, 28, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_he8d6983c__0)
                 ,  &(vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array)
                 , 0, ~0ULL);
    VL_WRITEF("PC Instruction Rom successfully loaded.\n");
    vlSelf->top__DOT__myPC__DOT__PC = 0U;
    VL_WRITEF("Initializing RAM with null values (0).\n");
    __Vtemp_hcba095ea__0[0U] = 0x2e6d656dU;
    __Vtemp_hcba095ea__0[1U] = 0x70757473U;
    __Vtemp_hcba095ea__0[2U] = 0x616d496eU;
    __Vtemp_hcba095ea__0[3U] = 0x72U;
    VL_READMEM_N(true, 32, 256, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_hcba095ea__0)
                 ,  &(vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array)
                 , 0, ~0ULL);
    VL_WRITEF("RAM successfully loaded.\nInitializing regFile with null values (0).\n");
    __Vtemp_h83cfa321__0[0U] = 0x2e6d656dU;
    __Vtemp_h83cfa321__0[1U] = 0x70757473U;
    __Vtemp_h83cfa321__0[2U] = 0x6c65496eU;
    __Vtemp_h83cfa321__0[3U] = 0x65676669U;
    __Vtemp_h83cfa321__0[4U] = 0x72U;
    VL_READMEM_N(true, 32, 32, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_h83cfa321__0)
                 ,  &(vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array)
                 , 0, ~0ULL);
    VL_WRITEF("regFile successfully loaded.\n");
}

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

VL_ATTR_COLD void Vtop___024root___settle__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    CData/*6:0*/ __Vtableidx2;
    // Body
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

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->a0 = VL_RAND_RESET_I(32);
    vlSelf->wr_en = VL_RAND_RESET_I(1);
    vlSelf->Eq = VL_RAND_RESET_I(1);
    vlSelf->alusrc = VL_RAND_RESET_I(1);
    vlSelf->aluCtrl = VL_RAND_RESET_I(3);
    vlSelf->extout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__PC_instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__write_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALUSrc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALU_ctrl = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__EQ = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ImmOp = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ImmSrc = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__imm_imm = VL_RAND_RESET_I(12);
    vlSelf->top__DOT__imm_branch = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__MemWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ResultSrc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__myPC__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__myPC__DOT__myPCreg__DOT__next_PC = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<28; ++__Vi0) {
        vlSelf->top__DOT__myPC__DOT__myRom__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__control_unit__DOT__Branch = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__control_unit__DOT__ALUOp = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ALU__DOT__rd1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALU__DOT__rd2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALU__DOT__ALUOp2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALU__DOT__ALUout = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->top__DOT__ALU__DOT__regFile1__DOT__regFile_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        vlSelf->top__DOT__ALU__DOT__ram1__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
