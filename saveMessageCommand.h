#ifndef SAVEMESSAGECOMMAND_H
#define SAVEMESSAGECOMMAND_H

#include "command.h"
#include <string>

/**
 * @class SaveMessageCommand
 * @brief Concrete command for saving messages.
 *
 * This class implements the Command interface to provide functionality
 * for saving messages in the chat application.
 */
class SaveMessageCommand : public Command {
public:

    SaveMessageCommand(ChatRoom* room, User* user, const std::string message)
        : Command(room, user, message) {};
    ~SaveMessageCommand() = default;
    /**
     * @brief Executes the command to save a message.
     */
    void execute() override;


};

#endif // SAVE_MESSAGE_COMMAND_H