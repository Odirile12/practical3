#include "Name2.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"
#include "chatRoom.h"
#include <iostream>
#include <thread>
#include <chrono>

Name2::Name2() : User("Bob") {
    std::cout << "Name2 user created: Bob" << std::endl;
}

void Name2::send(const std::string& message, chatRoom* room) {
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

void Name2::receive(const std::string& message, User* fromUser, chatRoom* room) {
    std::cout << "💬 [" << room->getName() << "] " << name << " received from " 
              << fromUser->getName() << ": " << message << std::endl;
}

void Name2::sendDelayedMessage(const std::string& message, chatRoom* room, int delaySeconds) {
    std::cout << "⏰ " << name << " scheduling message in " << delaySeconds << " seconds..." << std::endl;
    
    // Simulate delay (in real implementation, you'd use proper scheduling)
    if (delaySeconds > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(delaySeconds));
    }
    
    send("🚀 [DELAYED] " + message, room);
}