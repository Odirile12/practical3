#include "command.h"

Command::Command(chatRoom* room,User* user,const std::string message )
    : user(user), message(message), room(room) {}

void Command::execute() {
    return;
}
chatRoom* Command::getRoom() const {
    return room;
}
User* Command::getUser() const {
    return user;
}
std::string Command::getMessage() const {
    return message;
}
