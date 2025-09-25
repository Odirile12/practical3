#ifndef NoTIFICATION_H
#define NoTIFICATION_H
#include "Observer.h"

#include <iostream>
#include <string>
class Notification : public Observer {
public:
    Notification() = default;
    void update(const std::string& message, User* fromUser, chatRoom* room) override;
};

#endif // NoTIFICATION_H