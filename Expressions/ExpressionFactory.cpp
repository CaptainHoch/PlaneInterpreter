//
// Created by daniel on 12/9/18.
//

#include "ExpressionFactory.h"
#include "../Commands/RunFromFileCommand.h"

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

Expression *RunFromFileFactory::create(vector<std::string>::iterator &it) {
    string filename = *it;
    it++;
    return new ExpressionCommand(new RunFromFileCommand(ifstream(filename)));
}
