#ifndef NAME3_H
#define NAME3_H

#include "User.h"

class Name3 : public User {
private:
    int messageCount;
    
public:
    Name3();
    void send(const std::string& message, ChatRoom* room) override;
    void receive(const std::string& message, User* fromUser, ChatRoom* room) override;
    
    int getMessageCount() const;
    void sendFormattedMessage(const std::string& message, ChatRoom* room);
};

#endif