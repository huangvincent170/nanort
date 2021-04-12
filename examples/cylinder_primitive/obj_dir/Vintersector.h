// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VINTERSECTOR_H_
#define VERILATED_VINTERSECTOR_H_  // guard

#include "verilated_heavy.h"

//==========

class Vintersector__Syms;

//----------

VL_MODULE(Vintersector) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(reset,0,0);
    VL_IN(in_dummy,31,0);
    VL_OUT(out_dummy,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vintersector__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vintersector);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vintersector(VerilatedContext* contextp, const char* name = "TOP");
    Vintersector(const char* name = "TOP")
      : Vintersector(nullptr, name) {}
    /// Destroy the model; called (often implicitly) by application code
    ~Vintersector();
    
    // API METHODS
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp();
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(Vintersector__Syms* __restrict vlSymsp);
    void __Vconfigure(Vintersector__Syms* symsp, bool first);
  private:
    static QData _change_request(Vintersector__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vintersector__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Vintersector__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vintersector__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vintersector__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vintersector__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vintersector__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
