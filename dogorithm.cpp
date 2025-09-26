
#include "dogorithm.h"
#include "User.h"
#include "messageIterator.h"
#include <iostream>
#include <algorithm>

Dogorithm::Dogorithm() : ChatRoom("Dogorithm") {}

void Dogorithm::registerUser(User* user) {
    if (user && std::find(users.begin(), users.end(), user) == users.end()) {
        users.push_back(user);
        user->joinRoom(this);
        std::cout << user->getName() << " joined Dogorithm room." << std::endl;
    }
}

void Dogorithm::removeUser(User* user) {
    auto it = std::find(users.begin(), users.end(), user);
    if (it != users.end()) {
        users.erase(it);
        user->leaveRoom(this);
        std::cout << user->getName() << " left Dogorithm room." << std::endl;
    }
}

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

void Dogorithm::saveMessage(const std::string& message, User* fromUser) {
    if (std::find(users.begin(), users.end(), fromUser) != users.end()) {
        std::string savedMsg = "[SAVED] " + fromUser->getName() + ": " + message;
        chatHistory.push_back(savedMsg);
        std::cout << "Message saved in Dogorithm: " << savedMsg << std::endl;
    }
}

myIterator<User*>* Dogorithm::createUserIterator() {
    return new UserIterator(users);
}

myIterator<std::string>* Dogorithm::createMessageIterator() {
    return new MessageIterator(chatHistory);
}

const std::vector<User*>& Dogorithm::getUsers() const {
    return users;
}

const std::list<std::string>& Dogorithm::getChatHistory() const {
    return chatHistory;
}
