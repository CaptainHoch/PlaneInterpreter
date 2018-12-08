//
// Created by elikbelik77 on 12/7/18.
//

#ifndef PLANEINTERPRETER_EXPRESSIONCOMMAND_H
#define PLANEINTERPRETER_EXPRESSIONCOMMAND_H
#include "Expression.h"
#include "../Commands/Command.h"
class ExpressionCommand : public Expression {
private:
    Command* m_Command;
public:
    ExpressionCommand(Command* command) : m_Command(command) {

    }

    virtual int calculate() {
        return m_Command->execute();
    }

    virtual ~ExpressionCommand() {
        delete m_Command;
    }
};
#endif //PLANEINTERPRETER_EXPRESSIONCOMMAND_H
