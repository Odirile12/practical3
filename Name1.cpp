#include "Name1.h"
#include "sendMessageCommand.h"
#include "saveMessageCommand.h"
#include "ChatRoom.h"
#include <iostream>

Name1::Name1() : User("Alice") {
    std::cout << "Name1 user created: Alice" << std::endl;
}

void Name1::send(const std::string& message, ChatRoom* room) {
    if (!isInRoom(room)) {
        std::cout << "Error: " << name << " is not in " << room->getName() << "!" << std::endl;
        return;
    }
    
    if (message.empty()) {
        std::cout << "Error: " << name << " cannot send empty message!" << std::endl;
        return;
    }
    
    std::cout << name << " is sending message to " << room->getName() << ": " << message << std::endl;
    
    Command* sendCmd = new sendMessageCommand(room, this, message);
    Command* saveCmd = new SaveMessageCommand(room, this, message);
    
    addCommand(sendCmd);
    addCommand(saveCmd);
    executeCommands();
}

void Name1::receive(const std::string& message, User* fromUser, ChatRoom* room) {
    std::cout << "💬 [" << room->getName() << "] " << name << " received from " 
              << fromUser->getName() << ": " << message << std::endl;
}

