#include "Name2.h"
#include "sendMessageCommand.h"
#include "saveMessageCommand.h"
#include "ChatRoom.h"
#include <iostream>
#include <thread>
#include <chrono>

/**
 * @brief Constructs a Name2 user with the name "Bob".
 * 
 * Initializes the user and logs creation to the console.
 */
Name2::Name2() : User("Bob") {
    std::cout << "Name2 user created: Bob" << std::endl;
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
void Name2::send(const std::string& message, ChatRoom* room) {
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
void Name2::receive(const std::string& message, User* fromUser, ChatRoom* room) {
    std::cout << " [" << room->getName() << "] " << name << " received from "
              << fromUser->getName() << ": " << message << std::endl;
}

/**
 * @brief Sends a delayed message to a chat room.
 * 
 * Waits for a specified number of seconds before sending the message.
 * Uses the standard thread sleep mechanism to simulate delay.
 * 
 * @param message The message content to be sent.
 * @param room Pointer to the ChatRoom where the message should be sent.
 * @param delaySeconds Number of seconds to wait before sending.
 */
void Name2::sendDelayedMessage(const std::string& message, ChatRoom* room, int delaySeconds) {
    std::cout << name << " scheduling message in " << delaySeconds << " seconds..." << std::endl;

    // Simulate delay (in real implementation, you'd use proper scheduling)
    if (delaySeconds > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(delaySeconds));
    }

    send("[DELAYED] " + message, room);
}