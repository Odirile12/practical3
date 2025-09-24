// save_message_command.cpp

#include "saveMessageCommand.h"


/**
 * @brief Executes the command to save the message.
 */
void SaveMessageCommand::execute() {
    // Implementation for saving the message
    if(room == nullptr || user == nullptr) {
        return; // Safety check
    }
   room->saveMessage(message, user);
}

