#ifndef REGULAR_USER_H
#define REGULAR_USER_H

#include "User.h"

class RegularUser : public User {
public:
    RegularUser(const std::string& name) : User(name) {}

    // Uses default receive behavior from User
};

#endif
