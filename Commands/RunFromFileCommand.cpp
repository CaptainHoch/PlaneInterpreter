//
// Created by daniel on 12/9/18.
//

#include "RunFromFileCommand.h"

RunFromFileCommand::RunFromFileCommand(std::ifstream file) {
    Interpreter interpreter;
    this->m_exps_in_file = interpreter.parse(file);
}
