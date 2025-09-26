#include "command.h"

Command::Command(ChatRoom* room,User* user,const std::string message )
    : user(user), message(message), room(room) {}

void Command::execute() {
    return;
}


