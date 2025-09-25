#ifndef OBSERVER_H
#define OBSERVER_H
#include "user.h"
#include "chatroom.h"

#include <string>
class User;
class chatRoom;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& message, User* fromUser, chatRoom* room) = 0;
};

#endif