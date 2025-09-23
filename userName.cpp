#include "userName.h"

UserName::UserName(const std::string name) : User(name), name(name) {
    // Any UserName specific initialization
}
std::string UserName::getName() const {
    return this->name;
}
void UserName::send(std::string message, chatRoom* room) {
    room->sendMessage(message, this);
}
void UserName::joinRoom(chatRoom* room) {
    room->rgisterUser(this);
}
void UserName::leaveRoom(chatRoom* room) {
    room->removeUser(this);
}


