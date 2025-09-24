
#ifndef ADMIN_USER_H
#define ADMIN_USER_H

#include "User.h"

class AdminUser : public User {
public:
    AdminUser(const std::string& name) : User(name) {}

    // Override receive to add "[ADMIN]" prefix for clarity
    void receive(const std::string& message, User* fromUser, chatRoom* room) override;
};

#endif
