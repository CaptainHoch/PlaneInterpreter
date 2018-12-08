#include <utility>

//
// Created by elikbelik77 on 12/7/18.
//

#ifndef PLANEINTERPRETER_EXPRESSION_H
#define PLANEINTERPRETER_EXPRESSION_H
#include <vector>

class Expression {
protected:
    std::vector<Expression*> m_Operands;
public:
    Expression() = default;
    Expression(std::vector<Expression*>& operands)  : m_Operands(operands) {

    }

    virtual int calculate() = 0;
    //virtual std::vector<Expressions> getExpressions() = 0;
    virtual ~Expression() {
        for(Expression* exp : m_Operands) {
            delete exp;
        }
    }
};
#endif //PLANEINTERPRETER_EXPRESSION_H
