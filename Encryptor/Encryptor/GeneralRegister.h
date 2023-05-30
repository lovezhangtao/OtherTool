#pragma once
class GeneralRegister {
public:
    virtual ~GeneralRegister() {}
    virtual WORD getAddr() = 0;
};