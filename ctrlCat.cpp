#include "ctrlCat.h"
#include "User.h"
#include <iostream>
#include <algorithm>

/**
 * @brief Constructs the CtrlCat chat room with a predefined name.
 */
CtrlCat::CtrlCat() : ChatRoom("CtrlCat") {}

/**
 * @brief Registers a user to the CtrlCat chat room.
 * 
 * Adds the user to the room if they are not already present,
 * and notifies the user of the join event.
 * 
 * @param user Pointer to the User to be registered.
 */
void CtrlCat::registerUser(User* user) {
    if (user && std::find(users.begin(), users.end(), user) == users.end()) {
        users.push_back(user);
        user->joinRoom(this);
        std::cout << user->getName() << " joined CtrlCat room." << std::endl;
    }
}

/**
 * @brief Removes a user from the CtrlCat chat room.
 * 
 * Erases the user from the room's user list and notifies them of the departure.
 * 
 * @param user Pointer to the User to be removed.
 */
void CtrlCat::removeUser(User* user) {
    auto it = std::find(users.begin(), users.end(), user);
    if (it != users.end()) {
        users.erase(it);
        user->leaveRoom(this);
        std::cout << user->getName() << " left CtrlCat room." << std::endl;
    }
}

/**
 * @brief Sends a message from a user to all other users in the CtrlCat room.
 * 
 * Displays the message, saves it to history, and notifies all other users.
 * 
 * @param message The message content to be sent.
 * @param fromUser Pointer to the User sending the message.
 */
void CtrlCat::sendMessage(const std::string& message, User* fromUser) {
    if (std::find(users.begin(), users.end(), fromUser) != users.end()) {
        std::cout << "[CtrlCat] " << fromUser->getName() << ": " << message << std::endl;

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
 * @brief Saves a message to the CtrlCat room's history with a [SAVED] tag.
 * 
 * Only saves messages from users currently in the room.
 * 
 * @param message The message content to be saved.
 * @param fromUser Pointer to the User who sent the message.
 */
void CtrlCat::saveMessage(const std::string& message, User* fromUser) {
    if (std::find(users.begin(), users.end(), fromUser) != users.end()) {
        std::string savedMsg = "[SAVED] " + fromUser->getName() + ": " + message;
        chatHistory.push_back(savedMsg);
        std::cout << "Message saved in CtrlCat: " << savedMsg << std::endl;
    }
}

/**
 * @brief Creates an iterator for traversing users in the CtrlCat room.
 * @return Pointer to a UserIterator object.
 */
myIterator<User*>* CtrlCat::createUserIterator() {
    return new UserIterator(users);
}

/**
 * @brief Creates an iterator for traversing messages in the CtrlCat room's history.
 * @return Pointer to a MessageIterator object.
 */
myIterator<std::string>* CtrlCat::createMessageIterator() {
    return new MessageIterator(chatHistory);
}

/**
 * @brief Retrieves the list of users currently in the CtrlCat room.
 * @return Constant reference to the vector of User pointers.
 */
const std::vector<User*>& CtrlCat::getUsers() const {
    return users;
}

/**
 * @brief Retrieves the chat history of the CtrlCat room.
 * @return Constant reference to the list of message strings.
 */
const std::list<std::string>& CtrlCat::getChatHistory() const {
    return chatHistory;
}