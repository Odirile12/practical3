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
    /**
     * @brief Executes the command to save a message.
     */
    void execute() override;

    /**
     * @brief Sets the message to be saved.
     * @param message The message to save.
     */
    void setMessage(const std::string& message);

private:
    std::string message; ///< The message to be saved.
};

#endif // SAVE_MESSAGE_COMMAND_H