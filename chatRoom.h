#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <list>
#include "user.h"
#include "userIterator.h"
#include "messageIterator.h"

#include <list>
class chatRoom{
    private:
    std::list <User*>  user;
    std::list <std::string> message;

    public:
    chatRoom()=default;
    virtual void rgisterUser(User* u)=0;
    virtual void removeUser(User* u)=0;
    void sendMessage(std::string message,User* fromUser);
    void saveMessage(std::string message,User* fromUser);
    UserIterator* creatUserIterator();
    MessageIterator* creatMessageIterator();
    void addUser(User* u);
    void deleteUser(User* u);
    void receive(std::string message,User* fromUser);
    
};


#endif