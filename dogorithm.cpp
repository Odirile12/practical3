#include "dogorithm.h"
#include <iostream>

/**
 * @brief Constructs a dogorithm object.
 */
Dogorithm::Dogorithm() {
    // Constructor implementation
}
/**
 * @brief Adds a user to the chat room.
 * @param user The user to be added.
 */
void Dogorithm::registerUser(User* user) {
    // Implementation for registering a user
    users.push_back(user);
    std::cout << "[Dogorithm] " << "User registered.\n";
}
/**
 * @brief Sends a message from a user to the chat room.
 * 
 * @param user The user sending the message.
 * @param message The message to be sent.
 */
void Dogorithm::sendMessage(const std::string& message, User* fromUser) {
    // Implementation for sending a message
    std::cout << "[Dogorithm] " << fromUser->getName() << " sends: " << message << std::endl;
    saveMessage(message, fromUser);
    for (User* user : users) {
        if (user != fromUser) {
            user->receive(message, fromUser, this);
        }
    }
}
/**
 * @brief Removes a user from the chat room.
 *
 * @param user The user to be removed.
 */
void Dogorithm::removeUser(User *user)
{
    // Implementation for removing a user
    users.remove(user);
    std::cout << "[Dogorithm] " << "User removed.\n";
}
/**
 * @brief Saves a message to the chat history.
 * @param message The message content.
 * @param fromUser The user who sent the message.
 */
void Dogorithm::saveMessage(const std::string& message, User* fromUser) {
    // Implementation for saving a message
    chatHistrory.push_back(fromUser->getName() + ": " + message);
    std::cout << "[Dogorithm] " << "Message saved to history.\n";
}
/**
 * @brief Destructs a dogorithm object.
 */
Dogorithm::~Dogorithm() {
    // Destructor implementation
    
}