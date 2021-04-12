// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vintersector.h for the primary calling header

#include "Vintersector.h"
#include "Vintersector__Syms.h"

//==========

Vintersector::Vintersector(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vintersector__Syms* __restrict vlSymsp = __VlSymsp = new Vintersector__Syms(_vcontextp__, this, name());
    Vintersector* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vintersector::__Vconfigure(Vintersector__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vintersector::~Vintersector() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vintersector::_initial__TOP__1(Vintersector__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vintersector::_initial__TOP__1\n"); );
    Vintersector* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_WRITEF("Hello World!\n");
    VL_FINISH_MT("../../intersector.v", 12, "");
}

void Vintersector::_eval_initial(Vintersector__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vintersector::_eval_initial\n"); );
    Vintersector* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void Vintersector::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vintersector::final\n"); );
    // Variables
    Vintersector__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vintersector* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vintersector::_eval_settle(Vintersector__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vintersector::_eval_settle\n"); );
    Vintersector* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

void Vintersector::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vintersector::_ctor_var_reset\n"); );
    // Body
    reset = VL_RAND_RESET_I(1);
    in_dummy = VL_RAND_RESET_I(32);
    out_dummy = VL_RAND_RESET_I(32);
}
