//
// Created by elikbelik77 on 12/8/18.
//

#ifndef PLANEINTERPRETER_OPENDATASERVERCOMMAND_H
#define PLANEINTERPRETER_OPENDATASERVERCOMMAND_H
#include "Command.h"
class OpenDataServerCommand : public Command {
private :
    int m_Frequency;
    int m_Port;
public:
    OpenDataServerCommand(
    int frequency, int port) : m_Frequency(frequency), m_Port(port) {

    }



    virtual int execute() {
        //open server.
    }
};
#endif //PLANEINTERPRETER_OPENDATASERVERCOMMAND_H
