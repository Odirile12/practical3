#include "ChatRoom.h"
#include "User.h"
#include <algorithm>
#include <iostream>

ChatRoom::ChatRoom(const std::string& roomName) : name(roomName) {}

void ChatRoom::sendMessage(const std::string& message, User* fromUser) {
    // Deliver message to all users (Mediator pattern)
    for (User* user : users) {
        if (user != fromUser) {  // Don't send back to sender
            user->receive(message, fromUser, this);
        }
    }
    
    // Notify observers (Observer pattern)
    notify(message, fromUser, this);
    
    std::cout << "Message delivered to " << users.size() << " users in " << name << std::endl;
}

void ChatRoom::saveMessage(const std::string& message, User* fromUser) {
    std::string formattedMessage = fromUser->getName() + ": " + message;
    chatHistory.push_back(formattedMessage);
    std::cout << "Message saved to " << name << " history" << std::endl;
}
const std::vector<User*>& ChatRoom::getUsers() const { return users; }
    const std::list<std::string>& ChatRoom::getChatHistory() const { return chatHistory; }
