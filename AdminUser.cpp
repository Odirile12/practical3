#include "AdminUser.h"

#include <iostream>

void AdminUser::receive(const std::string &message, User *fromUser, ChatRoom *room)
{
    std::cout << "[ADMIN] " << name << " received from " << fromUser->getName() << ": " << message << std::endl;
};