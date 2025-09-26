#ifndef CHATROOM_H
#define CHATROOM_H

#include "Subject.h"
#include <string>
#include <vector>
#include <list>

class User;

template <typename T> class myIterator;


class ChatRoom: public Subject {
protected:
    std::string name;
    std::vector<User*> users;
    std::list<std::string> chatHistory;

public:
    ChatRoom(const std::string& roomName);
    virtual ~ChatRoom() = default;
    
    std::string getName() const { return name; }
    
    virtual void registerUser(User* user) = 0;
    virtual void removeUser(User* user) = 0;
    virtual void sendMessage(const std::string& message, User* fromUser) = 0;
    virtual void saveMessage(const std::string& message, User* fromUser) = 0;
    
    virtual myIterator<User*>* createUserIterator() = 0;
    virtual myIterator<std::string>* createMessageIterator() = 0;
    
    virtual const std::vector<User*>& getUsers() const = 0;
    virtual const std::list<std::string>& getChatHistory() const = 0;
};

#endif