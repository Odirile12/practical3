// save_message_command.cpp

#include "saveMessageCommand.h"


/**
 * @brief Executes the command to save the message.
 */
void SaveMessageCommand::execute() {
    // Implementation for saving the message
    this->getRoom()->saveMessage(this->getMessage() ,this->getUser());

}

/**
 * @brief Destructor for SaveMessageCommand.
 */
