// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vintersector__Syms.h"
#include "Vintersector.h"



// FUNCTIONS
Vintersector__Syms::~Vintersector__Syms()
{
}

Vintersector__Syms::Vintersector__Syms(VerilatedContext* contextp, Vintersector* topp, const char* namep)
    // Setup locals
    : VerilatedSyms{contextp}
    , __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
