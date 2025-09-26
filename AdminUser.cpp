#include "AdminUser.h"
#include "ChatRoom.h"
#include <iostream>

/**
 * @class AdminUser
 * @brief Represents an administrative user with elevated privileges in a chat room.
 * 
 * Inherits from the base User class and overrides messaging behavior to include
 * administrative tags. AdminUser can send and receive messages with special formatting.
 */
 
/**
 * @brief Constructs an AdminUser with a given name.
 * @param name The name of the admin user.
 */
AdminUser::AdminUser(const std::string& name) : User(name) {}

/**
 * @brief Sends a message to a chat room with an [ADMIN] tag.
 * 
 * Checks if the admin is part of the room before sending. The message is prefixed
 * with "[ADMIN]" to distinguish it from regular users.
 * 
 * @param message The message content to send.
 * @param room Pointer to the ChatRoom where the message should be sent.
 */
void AdminUser::send(const std::string& message, ChatRoom* room) {
    if (room && isInRoom(room)) {
        room->sendMessage("[ADMIN] " + message, this);
    }
}

/**
 * @brief Receives a message from another user in a chat room.
 * 
 * Displays the message in the console with admin-specific formatting, including
 * the room name and sender's name.
 * 
 * @param message The message content received.
 * @param fromUser Pointer to the User who sent the message.
 * @param room Pointer to the ChatRoom where the message was received.
 */
void AdminUser::receive(const std::string& message, User* fromUser, ChatRoom* room) {
    std::cout << "[ADMIN " << name << "] received in " << room->getName() 
              << " from " << fromUser->getName() << ": " << message << std::endl;
}