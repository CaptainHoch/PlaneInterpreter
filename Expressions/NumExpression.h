//
// Created by elikbelik77 on 12/7/18.
//

#ifndef PLANEINTERPRETER_NUMEXPRESSION_H
#define PLANEINTERPRETER_NUMEXPRESSION_H
#include "Expression.h"
class NumExpression : public Expression {
private:
    int m_Number;
public:
    NumExpression(int number) : m_Number(number) {

    }

    virtual int calculate() {
        return m_Number;
    }
};
#endif //PLANEINTERPRETER_NUMEXPRESSION_H
