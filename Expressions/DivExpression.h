//
// Created by elikbelik77 on 12/7/18.
//

#ifndef PLANEINTERPRETER_DIVEXPRESSION_H
#define PLANEINTERPRETER_DIVEXPRESSION_H
#include "Expression.h"
#include "NumExpression.h"

class DivExpression : public Expression {
public:
    DivExpression(int leftOperand, int rightOperand) {
        m_Operands.push_back(new NumExpression(leftOperand));
        m_Operands.push_back(new NumExpression(rightOperand));
    }



    DivExpression(Expression* left, Expression* right ) {
        m_Operands.push_back(left);
        m_Operands.push_back(right);
    }
    DivExpression(std::vector<Expression*> operands) {
        if (operands.size() != 2)
            throw std::exception();
        m_Operands = operands;
    }

    virtual int calculate() {
        return m_Operands[0]->calculate() / m_Operands[1]->calculate();
    }

};
#endif //PLANEINTERPRETER_DIVEXPRESSION_H
