#pragma once

#include <string>
#include <regex>
#include <iostream>

#include "Expression.h"
#include "Environment.h"

Env parseAndExecute(const std::string& line, Env env) {
    static std::regex letRegex(R"(let\s+(\w+)\s*=\s*([^;]+);?)");
    static std::regex printVarRegex(R"(print\(([^;]+)\);?)");
    static std::regex strRegex(R"("([^"]*) ")");
    std::smatch matches;

    if (std::regex_search(line, matches, letRegex)) {
        std::string varName = matches[1];
        std::string expression = matches[2];
        if (std::regex_match(expression, strRegex)) {
            std::cout << "String assignment not supported in this version." << std::endl;
        }
        else {
            int value = evaluateExpression(expression, env);
            env[varName] = value;
        }
    }
    else if (std::regex_search(line, matches, printVarRegex)) {
        std::string expression = matches[1];
        if (std::regex_match(expression, strRegex)) {
            std::cout << expression.substr(1, expression.length() - 2) << std::endl;
        }
        else {
            try {
                int result = evaluateExpression(expression, env);
                std::cout << result << std::endl;
            }
            catch (const std::out_of_range&) {
                std::cout << "Variable not found." << std::endl;
            }
        }
    }
    else {
        std::cout << "Command not recognized or invalid syntax." << std::endl;
    }

    return env;
}