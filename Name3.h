#ifndef NAME3_H
#define NAME3_H

#include "User.h"

class Name3 : public User {
private:
    int messageCount;
    
public:
    Name3();
    void send(const std::string& message, chatRoom* room) override;
    void receive(const std::string& message, User* fromUser, chatRoom* room) override;
    
    // Name3 specific methods (optional)
    int getMessageCount() const;
    void sendFormattedMessage(const std::string& message, chatRoom* room);
};

#endif