#include "saveMessageCommand.h"

/**
 * @brief Executes the command to save a message in the chat room.
 * 
 * Performs a safety check to ensure both the room and user are valid.
 * Then delegates the message saving to the ChatRoom's saveMessage method.
 */
void SaveMessageCommand::execute() {
    // Implementation for saving the message
    if (room == nullptr || user == nullptr) {
        return; // Safety check
    }
    room->saveMessage(message, user);
}