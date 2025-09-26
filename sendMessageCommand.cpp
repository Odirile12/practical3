#include "sendMessageCommand.h"

/**
 * @brief Executes the command to send a message to a chat room.
 * 
 * Performs a safety check to ensure both the room and user are valid.
 * Then delegates the message dispatch to the ChatRoom's sendMessage method.
 * This encapsulates the sending logic using the Command design pattern.
 */
void sendMessageCommand::execute() {
    if (room == nullptr || user == nullptr) {
        return;
    }
    room->sendMessage(message, user);
}