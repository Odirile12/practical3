// user.cpp

#include "user.h"

/**
 * @brief Constructs a User object with the given name.
 * 
 * @param name The name of the user.
 */
User::User(const std::string& name) : name(name) {}

/**
 * @brief Gets the name of the user.
 * 
 * @return The name of the user.
 */
std::string User::getName() const {
    return name;
}

/**
 * @brief Sends a message through the chat room.
 * 
 * @param message The message to be sent.
 */
void User::sendMessage(const std::string& message) {
    // Implementation for sending a message
}

/**
 * @brief Receives a message from the chat room.
 * 
 * @param message The message received.
 */
void User::receiveMessage(const std::string& message) {
    // Implementation for receiving a message
}