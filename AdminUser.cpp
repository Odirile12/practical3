#include "AdminUser.h"

#include <iostream>

void AdminUser::receive(const std::string &message, User *fromUser, chatRoom *room)
{
    std::cout << "[ADMIN] " << name << " received from " << fromUser->getName() << ": " << message << std::endl;
};