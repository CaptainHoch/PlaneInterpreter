//
// Created by elikbelik77 on 12/7/18.
//

#ifndef PLANEINTERPRETER_COMMAND_H
#define PLANEINTERPRETER_COMMAND_H
#include <string>
#include <vector>
#include <map>
class Command {
protected:
    std::vector<Command> m_NestedCommands;
public :
    Command() { }
    virtual int execute() = 0;
    virtual std::vector<Command> getNestedCommands() {
        return m_NestedCommands;
    }
};
#endif //PLANEINTERPRETER_COMMAND_H
