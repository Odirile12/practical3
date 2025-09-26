#ifndef REGULAR_USER_H
#define REGULAR_USER_H

#include "User.h"

class RegularUser : public User {
public:
    RegularUser(const std::string& name);
    
    void send(const std::string& message, ChatRoom* room) override;
    void receive(const std::string& message, User* fromUser, ChatRoom* room) override;
    
private:
    std::string userStatus;
};

#endif // REGULAR_USER_H
