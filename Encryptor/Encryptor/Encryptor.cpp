#include <iostream>
#include "CommandParser.h"


int main(int argc, char* argv[]) 
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
