#include "RegularUser.h"
#include "ChatRoom.h"
#include <iostream>

RegularUser::RegularUser(const std::string& name) : User(name) {}
void RegularUser::send(const std::string& message, ChatRoom* room) {
    if (room && isInRoom(room)) {
        room->sendMessage(message, this);
    }
}

void RegularUser::receive(const std::string& message, User* fromUser, ChatRoom* room) {
    std::cout << "[" << name << "] received in " << room->getName() 
              << " from " << fromUser->getName() << ": " << message << std::endl;
}
