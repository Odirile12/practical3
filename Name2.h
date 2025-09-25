#ifndef NAME2_H
#define NAME2_H

#include "User.h"

class Name2 : public User {
public:
    Name2();
    void send(const std::string& message, chatRoom* room) override;
    void receive(const std::string& message, User* fromUser, chatRoom* room) override;
    
    // Name2 specific methods (optional)
    void sendDelayedMessage(const std::string& message, chatRoom* room, int delaySeconds = 0);
};

#endif