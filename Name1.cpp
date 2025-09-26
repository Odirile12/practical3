#include "Name1.h"
#include "sendMessageCommand.h"
#include "saveMessageCommand.h"
#include "ChatRoom.h"
#include <iostream>

/**
 * @brief Constructs a Name1 user with the name "Alice".
 * 
 * Initializes the user and logs creation to the console.
 */
Name1::Name1() : User("Alice") {
    std::cout << "Name1 user created: Alice" << std::endl;
}

/**
 * @brief Sends a message to a chat room using command objects.
 * 
 * Validates that the user is in the room and that the message is not empty.
 * Then creates and queues two command objects: one to send the message,
 * and one to save it to history. Executes all queued commands.
 * 
 * @param message The message content to be sent.
 * @param room Pointer to the ChatRoom where the message should be sent.
 */
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

/**
 * @brief Receives a message from another user in a chat room.
 * 
 * Displays the message in the console with room and sender context.
 * 
 * @param message The message content received.
 * @param fromUser Pointer to the User who sent the message.
 * @param room Pointer to the ChatRoom where the message was received.
 */
void Name1::receive(const std::string& message, User* fromUser, ChatRoom* room) {
    std::cout << "[" << room->getName() << "] " << name << " received from "
              << fromUser->getName() << ": " << message << std::endl;
}