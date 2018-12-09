#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Interpreter.h"

using namespace std;

int main() {
    Interpreter interpreter;
    string line;
    getline(cin, line);
    istringstream str(line);
    interpreter.interpret(str);
}