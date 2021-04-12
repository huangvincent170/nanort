// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VINTERSECTOR__SYMS_H_
#define VERILATED_VINTERSECTOR__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vintersector.h"

// SYMS CLASS
class Vintersector__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vintersector*                  TOPp;
    
    // CREATORS
    Vintersector__Syms(VerilatedContext* contextp, Vintersector* topp, const char* namep);
    ~Vintersector__Syms();
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
