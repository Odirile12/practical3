#ifndef NoTIFICATION_H
#define NoTIFICATION_H
#include "Observer.h"

class Notification:public observer{
    public:
    Notification()=default;
    void update(std::string message,User* fromUser,chatRoom* room) override;
    ~Notification()=default;

};

#endif // NoTIFICATION_H