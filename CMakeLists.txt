cmake_minimum_required(VERSION 3.12)
project(PlaneInterpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(PlaneInterpreter main.cpp Interpreter.h Interpreter.cpp Expressions/Expression.h Commands/Command.h Expressions/ExpressionCommand.h Expressions/NumExpression.h Expressions/DivExpression.h Expressions/ExpressionFactory.h Utils.cpp Utils.h Commands/OpenDataServerCommand.h Expressions/ExpressionFactory.cpp Lexer.h Lexer.cpp Commands/RunFromFileCommand.h Commands/RunFromFileCommand.cpp)
