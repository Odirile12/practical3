#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>

#include "Observer.h"

class subject{
    public:
    virtual ~subject()=default;
    virtual void registerObserver(observer* o)=0;
    virtual void removeObserver(observer* o)=0;
    virtual void notifyObserver(std::string message,class User* fromUser,class chatRoom* room)=0;

};

#endif