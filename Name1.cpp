#include "Name1.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"
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
    
    // Create commands for sending and saving (Command Pattern)
    Command* sendCmd = new SendMessageCommand(room, this, message);
    Command* saveCmd = new SaveMessageCommand(room, this, message);
    
    addCommand(sendCmd);
    addCommand(saveCmd);
    executeCommands();
}

void Name1::receive(const std::string& message, User* fromUser, ChatRoom* room) {
    std::cout << "💬 [" << room->getName() << "] " << name << " received from " 
              << fromUser->getName() << ": " << message << std::endl;
}

void Name1::broadcastToAllRooms(const std::string& message) {
    std::cout << "\n📢 " << name << " broadcasting to all " << chatRooms.size() << " rooms: " << message << std::endl;
    for (ChatRoom* room : chatRooms) {
        send(message, room);
    }
}