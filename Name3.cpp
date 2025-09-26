#include "Name3.h"
#include "sendMessageCommand.h"
#include "saveMessageCommand.h"
#include "ChatRoom.h"
#include <iostream>
#include <iomanip>

/**
 * @brief Constructs a Name3 user with the name "Charlie".
 * 
 * Initializes the user and sets the message counter to zero.
 */
Name3::Name3() : User("Charlie"), messageCount(0) {
    std::cout << "Name3 user created: Charlie" << std::endl;
}

/**
 * @brief Sends a message to a chat room using command objects.
 * 
 * Validates room membership and message content. Increments the message counter,
 * then creates and queues send/save commands before executing them.
 * 
 * @param message The message content to be sent.
 * @param room Pointer to the ChatRoom where the message should be sent.
 */
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
    std::cout << name << " (message #" << messageCount << ") sending to "
              << room->getName() << ": " << message << std::endl;

    // Create commands for sending and saving (Command Pattern)
    Command* sendCmd = new sendMessageCommand(room, this, message);
    Command* saveCmd = new SaveMessageCommand(room, this, message);

    addCommand(sendCmd);
    addCommand(saveCmd);
    executeCommands();
}

/**
 * @brief Receives a message from another user in a chat room.
 * 
 * Displays the message with room and sender context.
 * 
 * @param message The message content received.
 * @param fromUser Pointer to the User who sent the message.
 * @param room Pointer to the ChatRoom where the message was received.
 */
void Name3::receive(const std::string& message, User* fromUser, ChatRoom* room) {
    std::cout << "[" << room->getName() << "] " << name << " received from "
              << fromUser->getName() << ": " << message << std::endl;
}

/**
 * @brief Retrieves the number of messages sent by this user.
 * @return The total message count.
 */
int Name3::getMessageCount() const {
    return messageCount;
}

/**
 * @brief Sends a formatted message with decorative tags and message count.
 * 
 * Prepends and appends visual markers and includes the next message number.
 * 
 * @param message The raw message content to be formatted and sent.
 * @param room Pointer to the ChatRoom where the message should be sent.
 */
void Name3::sendFormattedMessage(const std::string& message, ChatRoom* room) {
    std::string formattedMessage = "[" + std::to_string(messageCount + 1) + "] " + message;
    send(formattedMessage, room);
}