#ifndef ADMIN_USER_H
#define ADMIN_USER_H

#include "User.h"

class AdminUser : public User {
public:
    AdminUser(const std::string& name);
    
    void send(const std::string& message, ChatRoom* room) override;
    void receive(const std::string& message, User* fromUser, ChatRoom* room) override;
    

};


#endif