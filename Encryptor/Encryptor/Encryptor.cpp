#include <iostream>
#include "CommandParser.h"


int main(int argc, char* argv[]) 
{
    CommandParser cmdParser;
    cmdParser.registerOption("-v", "Verbose mode");
    cmdParser.registerOption("-d", "Debug mode");
    cmdParser.registerCommand("start", "Start the program");
    cmdParser.registerCommand("stop", "Stop the program");
    cmdParser.registerCommand("restart", "Restart the program");

    if (argc < 2) {
        cmdParser.showUsage();
        return 0;
    }

    cmdParser.parse(argc, argv);

    if (cmdParser.hasOption("-v")) {
        std::cout << "Verbose mode on" << std::endl;
    }
    if (cmdParser.hasOption("-d")) {
        std::cout << "Debug mode on" << std::endl;
    }

    std::vector<std::string> args = cmdParser.getArguments();
    for (const auto& arg : args) {
        std::cout << "Argument: " << arg << std::endl;
    }

    // Handle commands
    if (cmdParser.getArguments().empty()) {
        std::cout << "No command specified" << std::endl;
    }
    else {
        std::string cmd = cmdParser.getArguments()[0];
        std::cout << "Command: " << cmd << std::endl;
    }

    return 0;
}
