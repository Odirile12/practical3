#ifndef USERNAME_H
#define USERNAME_H

#include "user.h"

class UserName: public User {
    private:
        std::string name;
    public:
        UserName(const std::string name);
        void send(std::string message, chatRoom* room) override;
        std::string getName() const override;
        void joinRoom(chatRoom* room) override;
        void leaveRoom(chatRoom* room) override;
        void receive(std::string message, User* fromUser, chatRoom* room) override;

};


#endif