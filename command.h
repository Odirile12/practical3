#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "User.h"
#include "ChatRoom.h"

/**
 * @class Command
 * @brief Abstract base class representing a command in the chat system.
 * 
 * Encapsulates a messaging action involving a user and a chat room.
 * Derived classes should implement specific behaviors by overriding the execute method.
 */
class Command {
protected:
    /**
     * @brief Pointer to the chat room where the command will be executed.
     */
    ChatRoom* room;

    /**
     * @brief Pointer to the user who issued the command.
     */
    User* user;

    /**
     * @brief The message content associated with the command.
     */
    std::string message;

public:
    /**
     * @brief Constructs a Command object with the given room, user, and message.
     * @param room Pointer to the target ChatRoom.
     * @param user Pointer to the User issuing the command.
     * @param message The message content to be processed by the command.
     */
    Command(ChatRoom* room, User* user, const std::string message);

    /**
     * @brief Executes the command.
     * 
     * This is a pure virtual method that must be implemented by derived classes.
     */
    virtual void execute() = 0;

    /**
     * @brief Virtual destructor for safe polymorphic cleanup.
     */
    virtual ~Command() = default;
};

#endif // COMMAND_H