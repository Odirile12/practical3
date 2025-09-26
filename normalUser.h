#ifndef NORMALUSER_H
#define NORMALUSER_H

#include <list>
#include "command.h"

/**
 * @class NormalUser
 * @brief Represents a normal user in the chat system.
 * 
 * The NormalUser class extends the User class and acts as the invoker for commands.
 * It allows users to send and save messages through the command interface.
 */

#include "user.h"


class NormalUser : public User {

private:
    std::list<Command*> commandQueue;
public:
    NormalUser(const std::string& name);
    
    void addCommand(Command* command);
    void executeCommands();
};

#endif // NORMAL_USER_H