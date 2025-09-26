#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "User.h"
#include "ChatRoom.h"

/**
 * @brief Abstract Command class that defines the interface for command objects.
 */
class Command {
protected:
    ChatRoom* room;
    User* user;
    std::string message;

public:
    Command(ChatRoom* room, User* user, const std::string message);
    /**
     * @brief Executes the command.
     */
    virtual void execute() = 0;

    /**
     * @brief Destructor for the Command class.
     */
    virtual ~Command() = default; 
};

#endif // COMMAND_H