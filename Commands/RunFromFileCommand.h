//
// Created by daniel on 12/9/18.
//

#ifndef PLANEINTERPRETER_RUNFROMFILECOMMAND_H
#define PLANEINTERPRETER_RUNFROMFILECOMMAND_H

#include "Command.h"
#include "../Interpreter.h"
#include <fstream>

class RunFromFileCommand : public Command {
    std::vector<Expression*> m_exps_in_file;
public:
    RunFromFileCommand(std::ifstream file);
    int execute() override {
        for (Expression* e : this->m_exps_in_file) {
            e->calculate();
        }
    }
};

#endif //PLANEINTERPRETER_RUNFROMFILECOMMAND_H
