#ifndef SAVEMESSAGECOMMAND_H
#define SAVEMESSAGECOMMAND_H

#include "command.h"
#include <string>

/**
 * @class SaveMessageCommand
 * @brief A concrete Command that saves a message to a chat room's history.
 * 
 * Implements the Command interface to encapsulate the action of persisting
 * a message sent by a user into the chat room's message log.
 */
class SaveMessageCommand : public Command {
public:
    /**
     * @brief Constructs a SaveMessageCommand with the target room, user, and message.
     * @param room Pointer to the ChatRoom where the message should be saved.
     * @param user Pointer to the User who sent the message.
     * @param message The message content to be saved.
     */
    SaveMessageCommand(ChatRoom* room, User* user, const std::string message)
        : Command(room, user, message) {}

    /**
     * @brief Virtual destructor for safe polymorphic cleanup.
     */
    ~SaveMessageCommand() = default;

    /**
     * @brief Executes the command to save a message.
     * 
     * Delegates the saving operation to the ChatRoom's saveMessage method.
     */
    void execute() override;
};

#endif // SAVE_MESSAGE_COMMAND_H