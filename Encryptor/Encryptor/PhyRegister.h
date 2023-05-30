#pragma once
#include "GeneralRegister.h"

class PhyRegister : public GeneralRegister {
public:
    PhyRegister(WORD addr) : m_addr(addr) {}
    WORD getAddr() { return m_addr; }
private:
    WORD m_addr;
};