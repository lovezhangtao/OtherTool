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

    void registerOption(const std::string& opt, const std::string& desc) {
        m_optDescriptions[opt] = desc;
    }

    void parse(int argc, char* argv[]) {
        m_command = argv[1];
        for (int i = 2; i < argc; i++) {
            std::string arg = argv[i];
            if (arg[0] == '-') { // option
                m_options.push_back(arg);
            }
            else { // argument
                m_arguments.push_back(arg);
            }
        }
    }

    bool hasOption(const std::string& opt) const {
        for (const auto& o : m_options) {
            if (o == opt) {
                return true;
            }
        }
        return false;
    }

    std::vector<std::string> getArguments() const {
        return m_arguments;
    }

    void showUsage() const {
        std::cout << "Usage: " << m_command << " ";
        for (const auto& optDesc : m_optDescriptions) {
            std::cout << "[" << optDesc.first << "] ";
        }
        std::cout << "[arguments]" << std::endl;
        std::cout << std::endl;

        std::cout << "Arguments:" << std::endl;
        for (const auto& cmdDesc : m_cmdDescriptions) {
            std::cout << "  " << cmdDesc.first << "\t" << cmdDesc.second << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Options:" << std::endl;
        for (const auto& optDesc : m_optDescriptions) {
            std::cout << "  " << optDesc.first << "\t" << optDesc.second << std::endl;
        }
    }

private:
    std::string m_command;
    std::map<std::string, std::string> m_cmdDescriptions;
    std::vector<std::string> m_options;
    std::map<std::string, std::string> m_optDescriptions;
    std::vector<std::string> m_arguments;
};