#include "RegularUser.h"
#include "ChatRoom.h"
#include <iostream>

/**
 * @brief Constructs a RegularUser with a specified name.
 * 
 * Initializes the user by passing the name to the base User class.
 * 
 * @param name The name of the user.
 */
RegularUser::RegularUser(const std::string& name) : User(name) {}

/**
 * @brief Sends a message to a chat room.
 * 
 * Checks if the user is in the specified room before sending the message.
 * Delegates the actual message dispatch to the ChatRoom's sendMessage method.
 * 
 * @param message The message content to be sent.
 * @param room Pointer to the ChatRoom where the message should be sent.
 */
void RegularUser::send(const std::string& message, ChatRoom* room) {
    if (room && isInRoom(room)) {
        room->sendMessage(message, this);
    }
}

/**
 * @brief Receives a message from another user in a chat room.
 * 
 * Displays the message in the console with room and sender context.
 * 
 * @param message The message content received.
 * @param fromUser Pointer to the User who sent the message.
 * @param room Pointer to the ChatRoom where the message was received.
 */
void RegularUser::receive(const std::string& message, User* fromUser, ChatRoom* room) {
    std::cout << "[" << name << "] received in " << room->getName()
              << " from " << fromUser->getName() << ": " << message << std::endl;
}