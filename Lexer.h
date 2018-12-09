//
// Created by daniel on 12/9/18.
//

#ifndef PLANEINTERPRETER_LEXER_H
#define PLANEINTERPRETER_LEXER_H

#include <vector>
#include <string>
#include <istream>

class Lexer {
public:
    std::vector<std::string> lex(std::istream& s);
};


#endif //PLANEINTERPRETER_LEXER_H
