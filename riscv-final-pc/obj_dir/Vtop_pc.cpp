// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop_pc.h"
#include "Vtop_pc__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtop_pc::Vtop_pc(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop_pc__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , PCsrc{vlSymsp->TOP.PCsrc}
    , J{vlSymsp->TOP.J}
    , rst{vlSymsp->TOP.rst}
    , ImmOp{vlSymsp->TOP.ImmOp}
    , jalr_PC{vlSymsp->TOP.jalr_PC}
    , instr{vlSymsp->TOP.instr}
    , next_PC{vlSymsp->TOP.next_PC}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtop_pc::Vtop_pc(const char* _vcname__)
    : Vtop_pc(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop_pc::~Vtop_pc() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop_pc___024root___eval_debug_assertions(Vtop_pc___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop_pc___024root___eval_static(Vtop_pc___024root* vlSelf);
void Vtop_pc___024root___eval_initial(Vtop_pc___024root* vlSelf);
void Vtop_pc___024root___eval_settle(Vtop_pc___024root* vlSelf);
void Vtop_pc___024root___eval(Vtop_pc___024root* vlSelf);

void Vtop_pc::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_pc::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop_pc___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtop_pc___024root___eval_static(&(vlSymsp->TOP));
        Vtop_pc___024root___eval_initial(&(vlSymsp->TOP));
        Vtop_pc___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtop_pc___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
}

//============================================================
// Events and timing
bool Vtop_pc::eventsPending() { return false; }

uint64_t Vtop_pc::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtop_pc::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtop_pc___024root___eval_final(Vtop_pc___024root* vlSelf);

VL_ATTR_COLD void Vtop_pc::final() {
    Vtop_pc___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop_pc::hierName() const { return vlSymsp->name(); }
const char* Vtop_pc::modelName() const { return "Vtop_pc"; }
unsigned Vtop_pc::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vtop_pc::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtop_pc___024root__trace_init_top(Vtop_pc___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop_pc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_pc___024root*>(voidSelf);
    Vtop_pc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vtop_pc___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vtop_pc___024root__trace_register(Vtop_pc___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop_pc::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtop_pc::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtop_pc___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
