#ifndef NAME1_H
#define NAME1_H

#include "User.h"

class Name1 : public User {
public:
    Name1();
    void send(const std::string& message, chatRoom* room) override;
    void receive(const std::string& message, User* fromUser, chatRoom* room) override;
    
    // Name1 specific methods (optional)
    void broadcastToAllRooms(const std::string& message);
};

#endif