#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H
#include "command.h"
#include <string>

/**
 * @class sendMessageCommand
 * @brief Concrete command for sending messages in the chat system.
 *
 * This class implements the Command interface and encapsulates the
 * action of sending a message from a user to the chat room.
 */
class sendMessageCommand : public Command {
public:

    sendMessageCommand(ChatRoom* room, User* user, const std::string message)
        : Command(room, user, message) {};
        
    ~sendMessageCommand() = default;

    /**
     * @brief Executes the command to send the message.
     */
    void execute() override;

};

#endif // SEND_MESSAGE_COMMAND_H