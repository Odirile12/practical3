#include "AdminUser.h"
#include "ChatRoom.h"
#include <iostream>
AdminUser::AdminUser(const std::string& name) : User(name) {}

void AdminUser::send(const std::string& message, ChatRoom* room) {
    if (room && isInRoom(room)) {
        room->sendMessage("[ADMIN] " + message, this);
    }
}

void AdminUser::receive(const std::string& message, User* fromUser, ChatRoom* room) {
    std::cout << "[ADMIN " << name << "] received in " << room->getName() 
              << " from " << fromUser->getName() << ": " << message << std::endl;
}
