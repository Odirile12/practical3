#include "User.h"
#include "chatRoom.h"
#include "command.h"
#include <algorithm>
#include <iostream>

User::User(const std::string& userName) : name(userName) {}

User::~User() {
    clearCommandQueue();
}

std::string User::getName() const { 
    return name; 
}

const std::vector<chatRoom*>& User::getChatRooms() const { 
    return chatRooms; 
}

void User::joinRoom(chatRoom* room) {
    if (!isInRoom(room)) {
        chatRooms.push_back(room);
        room->registerUser(this);
        std::cout << name << " joined " << room->getName() << std::endl;
    }
}

void User::leaveRoom(chatRoom* room) {
    auto it = std::find(chatRooms.begin(), chatRooms.end(), room);
    if (it != chatRooms.end()) {
        chatRooms.erase(it);
        room->removeUser(this);
        std::cout << name << " left " << room->getName() << std::endl;
    }
}

bool User::isInRoom(chatRoom* room) const {
    return std::find(chatRooms.begin(), chatRooms.end(), room) != chatRooms.end();
}

void User::addCommand(Command* cmd) {
    commandQueue.push_back(cmd);
}

void User::executeCommands() {
    for (Command* cmd : commandQueue) {
        cmd->execute();
        delete cmd;
    }
    commandQueue.clear();
}

void User::clearCommandQueue() {
    for (Command* cmd : commandQueue) {
        delete cmd;
    }
    commandQueue.clear();
}