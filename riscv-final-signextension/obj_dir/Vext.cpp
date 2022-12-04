// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vext.h"
#include "Vext__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vext::Vext(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vext__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , ImmSrc{vlSymsp->TOP.ImmSrc}
    , inst{vlSymsp->TOP.inst}
    , ImmOp{vlSymsp->TOP.ImmOp}
    , rem{vlSymsp->TOP.rem}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vext::Vext(const char* _vcname__)
    : Vext(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vext::~Vext() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vext___024root___eval_initial(Vext___024root* vlSelf);
void Vext___024root___eval_settle(Vext___024root* vlSelf);
void Vext___024root___eval(Vext___024root* vlSelf);
#ifdef VL_DEBUG
void Vext___024root___eval_debug_assertions(Vext___024root* vlSelf);
#endif  // VL_DEBUG
void Vext___024root___final(Vext___024root* vlSelf);

static void _eval_initial_loop(Vext__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vext___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vext___024root___eval_settle(&(vlSymsp->TOP));
        Vext___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vext::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vext::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vext___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vext___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vext::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vext::final() {
    Vext___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vext::hierName() const { return vlSymsp->name(); }
const char* Vext::modelName() const { return "Vext"; }
unsigned Vext::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vext::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vext___024root__trace_init_top(Vext___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vext___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vext___024root*>(voidSelf);
    Vext__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vext___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vext___024root__trace_register(Vext___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vext::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vext___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
