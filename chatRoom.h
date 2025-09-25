// #ifndef CHATROOM_H
// #define CHATROOM_H

// #include <string>
// #include <list>
// #include "user.h"
// #include "userIterator.h"
// #include "messageIterator.h"

// #include <list>
// class chatRoom{

//     protected:
//     std::list <std::string> chatHistrory;
//     std::list <User*>  users;

//     public:
//     chatRoom()=default;
//     virtual ~chatRoom()=default;

//     virtual void registerUser(User* user) = 0;
//     virtual void removeUser(User* user) = 0;
//     virtual void sendMessage(const std::string& message, User* fromUser) = 0;
//     virtual void saveMessage(const std::string& message, User* fromUser) = 0;

// };


// #endif


#ifndef CHATROOM_H
#define CHATROOM_H

#include "subject.h"
#include <string>
#include <vector>
#include <list>

class User;
template <typename T>
class myIterator;

class chatRoom : public subject {
protected:
    std::string name;
    std::vector<User*> users;
    std::list<std::string> chatHistory;

public:
    chatRoom(const std::string& roomName);
    virtual ~chatRoom() = default;
    
    std::string getName() const { return name; }
    
    // Mediator pattern methods
    virtual void registerUser(User* user) = 0;
    virtual void removeUser(User* user) = 0;
    virtual void sendMessage(const std::string& message, User* fromUser)=0;
    virtual void saveMessage(const std::string& message, User* fromUser)=0;
    
    // Iterator pattern methods
    virtual myIterator<User*>* createUserIterator() = 0;
    virtual myIterator<std::string>* createMessageIterator() = 0;
    
    // Getters for iterators
    const std::vector<User*>& getUsers() const;
    const std::list<std::string>& getChatHistory() const ;
};

#endif