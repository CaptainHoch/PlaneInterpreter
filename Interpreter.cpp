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
int Interpreter::interpret(std::istream& stream) {
    std::vector<Expression> expression;
}


std::vector<Expression> Interpreter::parse(std::istream& stream) {
    std::vector<Expression> result;
    std::string line;
    while(!stream.eof()) {
        stream >> line;
        std::vector<std::string> indicies = split(line,' ');
        auto keywordIterator = m_KeywordMap.find(indicies[0]);
        if(keywordIterator == m_KeywordMap.end()) {
            throw std::exception();
        }
        auto f = keywordIterator->second;
        result.push_back(f.create(stream));
    }
    return result;
}

