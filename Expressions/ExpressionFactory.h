//
// Created by elikbelik77 on 12/7/18.
//

#ifndef PLANEINTERPRETER_EXPRESSIONFACTORY_H
#define PLANEINTERPRETER_EXPRESSIONFACTORY_H
#include "Expression.h"
#include "ExpressionCommand.h"
#include "../Commands/OpenDataServerCommand.h"
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <istream>
#include "../Utils.h"
#include "NumExpression.h"

using namespace std;

class ExpressionFactory {
public:
    virtual Expression* create(vector<std::string>::iterator& it) = 0;
};


Expression* shuntingYard(std::string& str_expression);

class OpenDataServerFactory : public ExpressionFactory{
public:
    virtual Expression* create(vector<std::string>::iterator& it) {
        // In the future, stoi will be replaced with shuntingYard
        Expression* e1 = new NumExpression(stoi(*it));     // first parameter
        it++;
        Expression* e2 = new NumExpression(stoi(*it));     // second parameter
        it++;
        return new ExpressionCommand(new OpenDataServerCommand(e1->calculate(), e2->calculate()));
    }
};

class RunFromFileFactory : public ExpressionFactory {
public:
    Expression *create(vector<std::string>::iterator &it) override;
};


#endif //PLANEINTERPRETER_EXPRESSIONFACTORY_H
