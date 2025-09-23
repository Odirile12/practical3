#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "user.h"
#include "chatRoom.h"

/**
 * @brief Abstract Command class that defines the interface for command objects.
 */
class Command {
private:
    chatRoom* room;
    User* user;
    std::string message;

public:
    Command(chatRoom* room, User* user, const std::string& message);
    /**
     * @brief Executes the command.
     */
    virtual void execute() = 0;

    /**
     * @brief Destructor for the Command class.
     */
    virtual ~Command() {}
};

#endif // COMMAND_H