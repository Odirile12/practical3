#ifndef NoTIFICATION_H
#define NoTIFICATION_H
#include "Observer.h"

#include <iostream>
#include <string>
class Notification : public Observer {
public:
    Notification() = default;
    void update(const std::string& message, User* fromUser, ChatRoom* room) override;
};

#endif // NoTIFICATION_H