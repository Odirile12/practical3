#ifndef NAME2_H
#define NAME2_H

#include "User.h"

class Name2 : public User {
public:
    Name2();
    void send(const std::string& message, ChatRoom* room) override;
    void receive(const std::string& message, User* fromUser, ChatRoom* room) override;
    
    void sendDelayedMessage(const std::string& message, ChatRoom* room, int delaySeconds = 0);
};

#endif