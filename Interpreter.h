
#ifndef PLANEINTERPRETER_INTERPRETER_H
#define PLANEINTERPRETER_INTERPRETER_H

#include <istream>
#include <string>
#include <vector>
#include "Expressions/Expression.h"
#include <map>
#include "Expressions/ExpressionFactory.h"

/**
 * Class responsible for interpreting the plane programming language.
 */
class Interpreter {
private:
    std::map<std::string,ExpressionFactory*> m_KeywordMap;
    std::map<std::string,double> m_SymbolMap;
public:
    Interpreter() {
        m_KeywordMap["openDataServer"] = new OpenDataServerFactory();
        m_KeywordMap["run"] = new RunFromFileFactory();

    }
    int interpret(std::istream& stream);
    std::vector<Expression> shuntingYard(std::string& str_expression);
    std::vector<Expression*> parse(std::istream& stream);
};

#endif //PLANEINTERPRETER_INTERPRETER_H
