#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>

#include "Observer.h"

class subject{
    protected:
    std::vector<Observer*> observers;
    public:
    virtual ~subject()=default;
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify(const std::string& message, User* fromUser, chatRoom* room);

};

#endif