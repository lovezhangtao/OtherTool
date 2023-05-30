#include "pch.h"
#include "CommandParser.h"
#include "MemRegister.h"
#include "PhyRegister.h"

const std::string key = "Hello, world!";


//https://en.wikipedia.org/wiki/XOR_cipher
//https://cplusplus.com/forum/windows/128374/
std::string encrypt(std::string msg, std::string key)
{
    // Make sure the key is at least as long as the message
    std::string tmp(key);
    while (key.size() < msg.size())
        key += tmp;

    // And now for the encryption part
    for (std::string::size_type i = 0; i < msg.size(); ++i)
        msg[i] ^= key[i];
    return msg;
}

std::string decrypt(std::string msg, std::string key)
{
    return encrypt(msg, key); // lol
}

int main()
{
    WORD num_value = 0xDFD2;
    auto reg_addr = std::make_unique<MemRegister>(num_value);
    WORD value = reg_addr->getAddr();

    std::stringstream ss;
    ss << "0x" << std::hex << value; // 在16进制整数前加上"0x"前缀，得到带0x的16进制字符串
    std::string str = ss.str(); // 获取字符串形式的带0x的16进制数
    std::cout << "Get Addr str: " << str << std::endl;

    std::string message = encrypt(str, key);
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
