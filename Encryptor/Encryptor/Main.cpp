#include "pch.h"
#include "CommandParser.h"
#include "MemRegister.h"
#include "PhyRegister.h"
#include "LoadDll.h"
#include "Encryptor.h"
#include "SpdLog.h"


int main()
{
    //PD_REG_INFO regInfo = { 0 };
    //regInfo.regType = MEM;

    //std::stringstream ss;
    //ss << "0x" << std::hex << 0xDFD2;
    //std::string str = ss.str();
    //std::string encrypt_addr = encrypt(str, key);
    //regInfo.encryptAddr = encrypt_addr.c_str();
    //std::cout << regInfo.encryptAddr[0] << std::endl;

    //std::string strAddr(regInfo.encryptAddr);
    //std::cout << strAddr << std::endl;

    //std::cout << decrypt(strAddr, key) << std::endl;

    //load_dll();
    basic_logfile_example();
    return 0;
};

int main3()
{
    WORD num_value = 0xDFD2;
    std::unique_ptr<GeneralRegister> reg(nullptr);
    reg = std::make_unique<MemRegister>(num_value);
    WORD value = reg->getAddr();

    std::stringstream ss;
    ss << "0x" << std::hex << value; // ��16��������ǰ����"0x"ǰ׺���õ���0x��16�����ַ���
    std::string str = ss.str(); // ��ȡ�ַ�����ʽ�Ĵ�0x��16������
    std::cout << "Get Addr str: " << str << std::endl;

    std::string message = encrypt(str, key);
    std::cout << "Length of string is: " << message.length() << std::endl;
    std::cout << "Encrypted: " << message;
    std::cout << "\nDecrypted: " << decrypt(message, key);

    return 0;
}

int main2(int argc, char* argv[])
{
    CommandParser cmdParser;
    cmdParser.registerCommand("-e", "Encrypt File");
    cmdParser.registerCommand("-d", "Decrypt File");

    if (argc < 2) {
        cmdParser.showUsage();
        return 0;
    }

    cmdParser.parse(argc, argv);

    if (cmdParser.showHelp()) {
        cmdParser.showUsage();
        return 0;
    }

    if (cmdParser.hasCmd("-e")) {
        std::cout << "Cmd: Encrypt" << std::endl;
    }
    if (cmdParser.hasCmd("-d")) {
        std::cout << "Cmd: Decrypt" << std::endl;
    }

    std::vector<std::string> args = cmdParser.getArguments();
    for (const auto& arg : args) {
        std::cout << "Argument: " << arg << std::endl;
    }

    return 0;
}
