#include "dogorithm.h"
#include "User.h"
#include "messageIterator.h"
#include <iostream>
#include <algorithm>

/**
 * @brief Constructs the Dogorithm chat room with a predefined name.
 */
Dogorithm::Dogorithm() : ChatRoom("Dogorithm") {}

/**
 * @brief Registers a user to the Dogorithm chat room.
 * 
 * Adds the user to the room if they are not already present,
 * and notifies the user of the join event.
 * 
 * @param user Pointer to the User to be registered.
 */
void Dogorithm::registerUser(User* user) {
    if (user && std::find(users.begin(), users.end(), user) == users.end()) {
        users.push_back(user);
        user->joinRoom(this);
        std::cout << user->getName() << " joined Dogorithm room." << std::endl;
    }
}

/**
 * @brief Removes a user from the Dogorithm chat room.
 * 
 * Erases the user from the room's user list and notifies them of the departure.
 * 
 * @param user Pointer to the User to be removed.
 */
void Dogorithm::removeUser(User* user) {
    auto it = std::find(users.begin(), users.end(), user);
    if (it != users.end()) {
        users.erase(it);
        user->leaveRoom(this);
        std::cout << user->getName() << " left Dogorithm room." << std::endl;
    }
}

/**
 * @brief Sends a message from a user to all other users in the Dogorithm room.
 * 
 * Displays the message, saves it to history, and notifies all other users.
 * 
 * @param message The message content to be sent.
 * @param fromUser Pointer to the User sending the message.
 */
void Dogorithm::sendMessage(const std::string& message, User* fromUser) {
    if (std::find(users.begin(), users.end(), fromUser) != users.end()) {
        std::cout << "[Dogorithm] " << fromUser->getName() << ": " << message << std::endl;

        chatHistory.push_back(fromUser->getName() + ": " + message);

        for (User* user : users) {
            if (user != fromUser) {
                user->receive(message, fromUser, this);
            }
        }

        notify(message, fromUser, this);
    }
}

/**
 * @brief Saves a message to the Dogorithm room's history with a [SAVED] tag.
 * 
 * Only saves messages from users currently in the room.
 * 
 * @param message The message content to be saved.
 * @param fromUser Pointer to the User who sent the message.
 */
void Dogorithm::saveMessage(const std::string& message, User* fromUser) {
    if (std::find(users.begin(), users.end(), fromUser) != users.end()) {
        std::string savedMsg = "[SAVED] " + fromUser->getName() + ": " + message;
        chatHistory.push_back(savedMsg);
        std::cout << "Message saved in Dogorithm: " << savedMsg << std::endl;
    }
}

/**
 * @brief Creates an iterator for traversing users in the Dogorithm room.
 * @return Pointer to a UserIterator object.
 */
myIterator<User*>* Dogorithm::createUserIterator() {
    return new UserIterator(users);
}

/**
 * @brief Creates an iterator for traversing messages in the Dogorithm room's history.
 * @return Pointer to a MessageIterator object.
 */
myIterator<std::string>* Dogorithm::createMessageIterator() {
    return new MessageIterator(chatHistory);
}

/**
 * @brief Retrieves the list of users currently in the Dogorithm room.
 * @return Constant reference to the vector of User pointers.
 */
const std::vector<User*>& Dogorithm::getUsers() const {
    return users;
}

/**
 * @brief Retrieves the chat history of the Dogorithm room.
 * @return Constant reference to the list of message strings.
 */
const std::list<std::string>& Dogorithm::getChatHistory() const {
    return chatHistory;
}