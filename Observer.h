#ifndef OBSERVER_H
#define OBSERVER_H
#include "User.h"
#include "ChatRoom.h"

#include <string>
class User;
class ChatRoom;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& message, User* fromUser, ChatRoom* room) = 0;
};

#endif