#ifndef AGECOMMAND_H
#define SENDMESSAGECOMMAND_H
#include "command.h"
#include <string>

/**
 * @class SendMessageCommand
 * @brief Concrete command for sending messages in the chat system.
 *
 * This class implements the Command interface and encapsulates the
 * action of sending a message from a user to the chat room.
 */
class SendMessageCommand : public Command {
public:


    /**
     * @brief Executes the command to send the message.
     */
    void execute();

    void saveMessage(const std::string& message);

};

#endif // SEND_MESSAGE_COMMAND_H