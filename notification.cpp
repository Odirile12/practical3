#include "notification.h"

/**
 * @brief Handles notification updates when a new message is sent in a chat room.
 * 
 * Displays a formatted notification message indicating the room name,
 * sender's name, and message content.
 * 
 * @param message The content of the message sent.
 * @param fromUser Pointer to the User who sent the message.
 * @param room Pointer to the ChatRoom where the message was sent.
 */
void Notification::update(const std::string& message, User* fromUser, ChatRoom* room) {
    std::cout << "[NOTIFICATION] New message in " << room->getName()
              << " from " << fromUser->getName() << ": " << message << std::endl;
}