#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

class CommandParser {
public:
    CommandParser() {}
    virtual ~CommandParser() {}

    void registerCommand(const std::string& cmd, const std::string& desc) {
        m_cmdDescriptions[cmd] = desc;
    }

    void parse(int argc, char* argv[]) {
        std::string cmd = argv[1];
        if (cmd == "-h" || cmd == "--help") { // help option
            m_showHelp = true;
            return;
        }
        m_command = cmd;
        m_cmds.push_back(m_command);
        for (int i = 2; i < argc; i++) {
            std::string arg = argv[i];
             // argument
             m_arguments.push_back(arg);
        }
    }

    bool hasCmd(const std::string& cmd) const {
        for (const auto& c : m_cmds) {
            if (c == cmd) {
                return true;
            }
        }
        return false;
    }

    std::vector<std::string> getArguments() const {
        return m_arguments;
    }

    bool showHelp() const {
        return m_showHelp;
    }

    void showUsage(const std::string& error = "") const {
        if (!error.empty()) {
            std::cout << error << std::endl << std::endl;
        }
        std::cout << "Usage: " << m_command << " ";
        std::cout << "[arguments]" << std::endl;
        std::cout << std::endl;

        std::cout << "Cmds:" << std::endl;
        for (const auto& cmdDesc : m_cmdDescriptions) {
            std::cout << "  " << cmdDesc.first << "\t" << cmdDesc.second << std::endl;
        }
    }

private:
    std::string m_command = "[cmd]";
    std::map<std::string, std::string> m_cmdDescriptions;
    std::vector<std::string> m_cmds;
    std::vector<std::string> m_arguments;
    bool m_showHelp = false;
};