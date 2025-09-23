#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <list>
#include "user.h"
#include "userIterator.h"
#include "messageIterator.h"

#include <list>;
class chatRoom{
    private:
    std::list <User*>  user;
    std::list <std::string> message;

    public:
    chatRoom()=default;
    void rgisterUser(User* u);
    void removeUser(User* u);
    void sendMessage(std::string message,User* fromUser);
    void saveMessage(std::string message,User* fromUser);
    UserIterator* creatUserIterator();
    MessageIterator* creatMessageIterator();
    
};


#endif