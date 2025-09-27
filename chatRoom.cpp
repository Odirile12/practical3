#include "ChatRoom.h"
#include "Observer.h"
#include "User.h"
#include <algorithm>
#include <iostream>

/**
 * @brief Constructs a ChatRoom with a given name.
 * @param roomName The name of the chat room.
 */
ChatRoom::ChatRoom(const std::string& roomName) : name(roomName) {}

/**
 * @brief Sends a message to all users in the chat room except the sender.
 * 
 * Iterates through the list of users and calls their receive method.
 * Also triggers any observers via notify and logs the delivery.
 * 
 * @param message The message content to be sent.
 * @param fromUser Pointer to the User who is sending the message.
 */
void ChatRoom::sendMessage(const std::string& message, User* fromUser) {
    for (User* user : users) {
        if (user != fromUser) {
            user->receive(message, fromUser, this);
        }
    }

    notify(message, fromUser, this);

    std::cout << "Message delivered to " << users.size() << " users in " << name << std::endl;
}

/**
 * @brief Saves a message to the chat room's history.
 * 
 * Formats the message with the sender's name and appends it to the chat history.
 * Logs the save operation to the console.
 * 
 * @param message The message content to be saved.
 * @param fromUser Pointer to the User who sent the message.
 */
void ChatRoom::saveMessage(const std::string& message, User* fromUser) {
    std::string formattedMessage = fromUser->getName() + ": " + message;
    chatHistory.push_back(formattedMessage);
    std::cout << "Message saved to " << name << " history" << std::endl;
}

/**
 * @brief Retrieves the list of users currently in the chat room.
 * @return A constant reference to the vector of User pointers.
 */
const std::vector<User*>& ChatRoom::getUsers() const {
    return users;
}

void ChatRoom::addObserver(Observer* observer) {
    if (observer && std::find(observers.begin(), observers.end(), observer) == observers.end()) {
        observers.push_back(observer);
    }
}

void ChatRoom::removeObserver(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void ChatRoom::notify(const std::string& message, User* fromUser, ChatRoom* room) {
    for (Observer* observer : observers) {
        observer->update(message, fromUser, room);
    }
}

/**
 * @brief Retrieves the chat history of the room.
 * @return A constant reference to the list of formatted message strings.
 */
const std::list<std::string>& ChatRoom::getChatHistory() const {
    return chatHistory;
}