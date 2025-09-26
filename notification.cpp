#include "notification.h"


void Notification ::update(const std::string& message, User* fromUser, ChatRoom* room) {
    std::cout << "[NOTIFICATION] New message in " << room->getName() 
                << " from " << fromUser->getName() << ": " << message << std::endl;
}