#include "chatRoom.h"
 
void chatRoom::addUser(User* u){
    user.push_back(u);
}
void chatRoom::deleteUser(User* u){
    user.remove(u);
}

