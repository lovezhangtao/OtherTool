#pragma once

typedef enum _REG_TYPE {
	MEM = 0,
	PHY
} REG_TYPE;

typedef struct _PD_REG_INFO
{
	char* encryptAddr;
	REG_TYPE regType;
} PD_REG_INFO;

typedef PD_REG_INFO(*pfn_EC_GetRegisterAddr)();

extern "C"  __declspec(dllexport) PD_REG_INFO GetRegisterAddr();
