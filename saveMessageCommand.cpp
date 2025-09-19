// save_message_command.cpp

#include "saveMessageCommand.h"

/**
 * @brief Constructs a SaveMessageCommand object.
 * 
 * @param message The message to be saved.
 */
SaveMessageCommand::SaveMessageCommand(const std::string& message) : message_(message) {}

/**
 * @brief Executes the command to save the message.
 */
void SaveMessageCommand::execute() {
    // Implementation for saving the message
}

/**
 * @brief Destructor for SaveMessageCommand.
 */
SaveMessageCommand::~SaveMessageCommand() {}