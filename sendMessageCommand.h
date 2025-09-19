#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

/**
 * @class SendMessageCommand
 * @brief Concrete command for sending messages in the chat system.
 *
 * This class implements the Command interface and encapsulates the
 * action of sending a message from a user to the chat room.
 */
class SendMessageCommand {
public:
    /**
     * @brief Constructs a SendMessageCommand with the specified parameters.
     * @param user The user sending the message.
     * @param message The message to be sent.
     */
    SendMessageCommand(User* user, const std::string& message);

    /**
     * @brief Executes the command to send the message.
     */
    void execute();

private:
    User* user; ///< The user sending the message.
    std::string message; ///< The message to be sent.
};

#endif // SEND_MESSAGE_COMMAND_H