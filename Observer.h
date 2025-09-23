#ifndef ObSERVER_H
#define ObSERVER_H
#include <string>
#include "user.h"
#include "chatRoom.h"

class observer{
    public:
    virtual ~observer()=default;
    virtual void update(std::string message,User* fromUser,chatRoom* room)=0;

};

#endif