//
// Created by daniel on 12/9/18.
//


#include "Lexer.h"

using namespace std;
std::vector<std::string> Lexer::lex(std::istream &s) {
    vector<string> result;

    string temp;
    while (s >> temp) {
        result.push_back(temp);
    }

    return result;
}
