
#include "ctrlCat.h"
#include "User.h"
#include <iostream>
#include <algorithm>

CtrlCat::CtrlCat() : ChatRoom("CtrlCat") {}

void CtrlCat::registerUser(User* user) {
    if (user && std::find(users.begin(), users.end(), user) == users.end()) {
        users.push_back(user);
        user->joinRoom(this);
        std::cout << user->getName() << " joined CtrlCat room." << std::endl;
    }
}

void CtrlCat::removeUser(User* user) {
    auto it = std::find(users.begin(), users.end(), user);
    if (it != users.end()) {
        users.erase(it);
        user->leaveRoom(this);
        std::cout << user->getName() << " left CtrlCat room." << std::endl;
    }
}

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

void CtrlCat::saveMessage(const std::string& message, User* fromUser) {
    if (std::find(users.begin(), users.end(), fromUser) != users.end()) {
        std::string savedMsg = "[SAVED] " + fromUser->getName() + ": " + message;
        chatHistory.push_back(savedMsg);
        std::cout << "Message saved in CtrlCat: " << savedMsg << std::endl;
    }
}

myIterator<User*>* CtrlCat::createUserIterator() {
    return new UserIterator(users);
}

myIterator<std::string>* CtrlCat::createMessageIterator() {
    return new MessageIterator(chatHistory);
}

const std::vector<User*>& CtrlCat::getUsers() const {
    return users;
}

const std::list<std::string>& CtrlCat::getChatHistory() const {
    return chatHistory;
}