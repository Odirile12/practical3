#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "command.h"
#include <string>

/**
 * @class sendMessageCommand
 * @brief Concrete command for sending messages in the chat system.
 * 
 * Implements the Command interface and encapsulates the action of sending
 * a message from a user to a chat room. This promotes decoupling and supports
 * extensibility via the Command design pattern.
 */
class sendMessageCommand : public Command {
public:
    /**
     * @brief Constructs a sendMessageCommand with the target room, user, and message.
     * @param room Pointer to the ChatRoom where the message should be sent.
     * @param user Pointer to the User who is sending the message.
     * @param message The message content to be sent.
     */
    sendMessageCommand(ChatRoom* room, User* user, const std::string message)
        : Command(room, user, message) {}

    /**
     * @brief Virtual destructor for safe polymorphic cleanup.
     */
    ~sendMessageCommand() = default;

    /**
     * @brief Executes the command to send the message.
     * 
     * Delegates the message dispatch to the ChatRoom's sendMessage method.
     */
    void execute() override;
};

#endif // SEND_MESSAGE_COMMAND_H