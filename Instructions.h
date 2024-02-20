#pragma once

#include <functional>
#include <map>
#include <string>

#include "Environment.h"

using Instruction = std::function<Env(const Env&)>;

Instruction parsePrint(const std::string& args) {
    return [args](const Env& env) -> Env {
        auto it = env.find(args);
        if (it != env.end()) {
            std::cout << it->second << "\n";
        }
        else {
            std::cout << "Variable '" << args << "' not found.\n";
        }
        return env;
    };
}

Instruction parseLet(const std::string& args) {
    std::smatch matches;
    static std::regex letRegex(R"(let\s+(\w+)\s*=\s*(\d+))");
    if (std::regex_search(args, matches, letRegex)) {
        std::string varName = matches[1];
        int value = std::stoi(matches[2]);
        return [varName, value](Env env) -> Env {
            env[varName] = value;
            return env;
        };
    }
    return [](const Env& env) -> Env { return env; };
}
