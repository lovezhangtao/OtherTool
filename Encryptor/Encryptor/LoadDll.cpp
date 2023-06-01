#include "pch.h"
#include "ECReadPDRegister.h"
#include "Encryptor.h"
#include "LoadDll.h"

void load_dll()
{
    HINSTANCE hInstLibrary = LoadLibrary(L"ECReadPDRegister.dll");
    if (hInstLibrary != nullptr) {
        std::cout << "ECReadPDRegisterd.dll loaded successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to load ECReadPDRegisterd.dll!" << std::endl;
        return;
    }
    pfn_EC_GetRegisterAddr pfnEC_GetRegisterAddr = NULL;
    pfnEC_GetRegisterAddr = (pfn_EC_GetRegisterAddr)GetProcAddress(hInstLibrary, ("GetRegisterAddr"));
    if (pfnEC_GetRegisterAddr)
    {
        PD_REG_INFO pd_reg_info = pfnEC_GetRegisterAddr();
        std::cout << "encryptAddr: " << pd_reg_info.encryptAddr << std::endl;
        std::cout << "regType: " << pd_reg_info.regType << std::endl;

        std::string strAddr(pd_reg_info.encryptAddr);

        std::cout << "decrypt Addr: " << decrypt(pd_reg_info.encryptAddr, key) << std::endl;
    }
    if (hInstLibrary)
    {
        FreeLibrary(hInstLibrary);
    }
}
