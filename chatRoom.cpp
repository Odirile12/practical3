#include "chatRoom.h"
 
void chatRoom::addUser(User* u){
    user.push_back(u);
}
void chatRoom::deleteUser(User* u){
    user.remove(u);
}
void chatRoom::saveMessage(std::string message,User* fromUser){
    std::string fullMessage=fromUser->getName()+": "+message;
    this->message.push_back(fullMessage);
}
void chatRoom::sendMessage(std::string message,User* fromUser){

    saveMessage(message,fromUser);
}

