#pragma once
#include "GeneralRegister.h"

class MemRegister : public GeneralRegister {
public:
    MemRegister(WORD addr) : m_addr(addr) {}
    WORD getAddr() { return m_addr; }
private:
    WORD m_addr;
};