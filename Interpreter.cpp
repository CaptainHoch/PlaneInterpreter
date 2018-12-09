#include "Interpreter.h"

//
// Created by elikbelik77 on 12/7/18.
//
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include "Utils.h"
#include "Expressions/Expression.h"
#include "Lexer.h"

using namespace std;

int Interpreter::interpret(std::istream& stream) {

    std::vector<Expression*> expressions = this->parse(stream);
    for (Expression* exp : expressions) {
        exp->calculate();
    }
}


std::vector<Expression*> Interpreter::parse(std::istream& stream) {
    Lexer lexer;
    vector<string> to_parse = lexer.lex(stream);
    vector<Expression*> result;
    auto parse_iterator = to_parse.begin();
    while(parse_iterator != to_parse.end()) {
        auto keywordIterator = m_KeywordMap.find(*parse_iterator);
        parse_iterator++;
        if(keywordIterator == m_KeywordMap.end()) {
            throw std::exception();
        }
        auto f = keywordIterator->second;
        result.push_back(f->create(parse_iterator));
    }

    return result;
}

