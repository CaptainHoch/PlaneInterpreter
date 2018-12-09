//
// Created by elikbelik77 on 12/7/18.
//

// Try

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
class ExpressionFactory {

    virtual Expression* create(std::istream& stream) = 0;
};


Expression* shuntingYard(std::string& str_expression) {
    std::stack<char> st;
    std::queue<std::string> q;
    std::string currentToken;
    std::map<char,int> precedanceMap = {{'+',0},{'-',0}, {'*',1}, {'/',1}};
    int bytes_read = 0;
    while(bytes_read < str_expression.size()) {
        if(str_expression.c_str()[bytes_read] > '0' && str_expression.c_str()[bytes_read] < '9') {
            currentToken.push_back(str_expression.c_str()[bytes_read]);
        }
        else {
            q.push(currentToken);
            currentToken = "";
        }
        if(str_expression.c_str()[bytes_read] == '+' ||
                str_expression.c_str()[bytes_read] == '/' ||
                str_expression.c_str()[bytes_read] == '*' ||
                str_expression.c_str()[bytes_read] == '-' ) {
            if(!st.empty() &&
             precedanceMap[st.top()] > precedanceMap[str_expression.c_str()[bytes_read]]) {
                q.push(std::string(1,st.top()));
                st.pop();
            }
            std::string op(1,str_expression.c_str()[bytes_read]);
            q.push(op);
        }
        else if (str_expression.c_str()[bytes_read] == '(') {
            st.push(str_expression.c_str()[bytes_read]);
        }
        else if (str_expression.c_str()[bytes_read] == ')') {
            while(st.top() != '(') {
                if(st.empty()) {
                    throw std::exception();
                }
                q.push(std::string(1,st.top()));
                st.pop();
            }
        }
        bytes_read++;
    }
    while (!st.empty()) {
        q.push(std::string(1,st.top()));
        st.pop();
    }
    //not finished.

}

class OpenDataServerFactory : public ExpressionFactory{
    virtual Expression* create(std::istream& stream) {
        std::string line;
        stream >> line;
        std::vector<std::string> indicies = split(line, ' ');
        std::vector<Expression*> parameters;
        for(std::string split_param : indicies) {
            parameters.push_back(shuntingYard(split_param));
        }
        return new ExpressionCommand(new OpenDataServerCommand(parameters[0]->calculate()(), parameters[1]->calculate()));
    }
};


#endif //PLANEINTERPRETER_EXPRESSIONFACTORY_H
