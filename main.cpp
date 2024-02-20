#include <iostream>
#include <string>

#include "Parser.h"
#include "Environment.h"
#include "Instructions.h"
#include "Expression.h"

void runInterpreter() {
    Env env;
    std::string line;

    std::cout << "FlextaScript Interactive Interpreter" << std::endl;
    std::cout << "Type 'exit' to quit." << std::endl;

    while (true) {
        std::cout << ">>> ";
        std::getline(std::cin, line);
        if (line == "exit") {
            break;
        }
        env = parseAndExecute(line, env);
    }
}

int main()
{
    runInterpreter();
}
