#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <list>
#include "user.h"
#include "userIterator.h"
#include "messageIterator.h"

#include <list>
class chatRoom{

    protected:
    std::list <std::string> chatHistrory;
    std::list <User*>  users;

    public:
    chatRoom()=default;
    virtual ~chatRoom()=default;

    virtual void registerUser(User* user) = 0;
    virtual void removeUser(User* user) = 0;
    virtual void sendMessage(const std::string& message, User* fromUser) = 0;
    virtual void saveMessage(const std::string& message, User* fromUser) = 0;

};


#endif