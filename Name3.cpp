#include "Name3.h"
#include "sendMessageCommand.h"
#include "saveMessageCommand.h"
#include "ChatRoom.h"
#include <iostream>
#include <iomanip>

Name3::Name3() : User("Charlie"), messageCount(0) {
    std::cout << "Name3 user created: Charlie" << std::endl;
}

void Name3::send(const std::string& message, ChatRoom* room) {
    if (!isInRoom(room)) {
        std::cout << "Error: " << name << " is not in " << room->getName() << "!" << std::endl;
        return;
    }
    
    if (message.empty()) {
        std::cout << "Error: " << name << " cannot send empty message!" << std::endl;
        return;
    }
    
    messageCount++;
    std::cout << "📝 " << name << " (message #" << messageCount << ") sending to " 
              << room->getName() << ": " << message << std::endl;
    
    // Create commands for sending and saving (Command Pattern)
    Command* sendCmd = new sendMessageCommand(room, this, message);
    Command* saveCmd = new SaveMessageCommand(room, this, message);
    
    addCommand(sendCmd);
    addCommand(saveCmd);
    executeCommands();
}

void Name3::receive(const std::string& message, User* fromUser, ChatRoom* room) {
    std::cout << "💬 [" << room->getName() << "] " << name << " received from " 
              << fromUser->getName() << ": " << message << std::endl;
}

int Name3::getMessageCount() const {
    return messageCount;
}

void Name3::sendFormattedMessage(const std::string& message, ChatRoom* room) {
    std::string formattedMessage = "✨ [" + std::to_string(messageCount + 1) + "] " + message + " ✨";
    send(formattedMessage, room);
}