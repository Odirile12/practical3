#include "sendMessageCommand.h"

/**
 * @brief Constructs a SendMessageCommand with the specified message.
 * 
 * @param message The message to be sent.
 */


/**
 * @brief Executes the command to send the message.
 * 
 * This method will interact with the mediator to send the message to the appropriate users.
 */
void SendMessageCommand::execute() {
    if(room == nullptr || user == nullptr) {
        return;
    }
    room->sendMessage(message, user);
}