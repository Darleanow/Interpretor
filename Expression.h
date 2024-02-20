#pragma once

#include <string>

#include "Environment.h"

int evaluateExpression(const std::string& expression, const Env& env) {
    std::smatch matches;
    static std::regex opRegex(R"((\w+|\d+)\s*([+-/*])\s*(\w+|\d+))");

    if (std::regex_search(expression, matches, opRegex)) {
        std::string left = matches[1];
        std::string op = matches[2];
        std::string right = matches[3];
        int leftVal, rightVal;

        // Check if the operands are variables or numbers and retrieve their values
        leftVal = std::regex_match(left, std::regex(R"(\d+)")) ? std::stoi(left) : env.at(left);
        rightVal = std::regex_match(right, std::regex(R"(\d+)")) ? std::stoi(right) : env.at(right);

        // Perform the operation
        switch (op[0]) {
            case '+': return leftVal + rightVal;
            case '-': return leftVal - rightVal;
            case '*': return leftVal * rightVal;
            case '/': return rightVal != 0 ? leftVal / rightVal : 0; // Guard against division by zero
            default: return 0; // Should not reach here
        }
    }
    return 0;
}
