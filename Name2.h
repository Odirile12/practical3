#ifndef NAME2_H
#define NAME2_H

#include "User.h"

/**
 * @class Name2
 * @brief A concrete implementation of User representing a participant named "Bob".
 * 
 * Overrides messaging behavior to include command-based execution and supports delayed messaging.
 */
class Name2 : public User {
public:
    /**
     * @brief Constructs a Name2 user with the name "Bob".
     */
    Name2();

    /**
     * @brief Sends a message to a chat room using command objects.
     * 
     * Validates room membership and message content before queuing send and save commands.
     * 
     * @param message The message content to be sent.
     * @param room Pointer to the ChatRoom where the message should be sent.
     */
    void send(const std::string& message, ChatRoom* room) override;

    /**
     * @brief Receives a message from another user in a chat room.
     * 
     * Displays the message with room and sender context.
     * 
     * @param message The message content received.
     * @param fromUser Pointer to the User who sent the message.
     * @param room Pointer to the ChatRoom where the message was received.
     */
    void receive(const std::string& message, User* fromUser, ChatRoom* room) override;

    /**
     * @brief Sends a message to a chat room after a specified delay.
     * 
     * Simulates a scheduled message dispatch using a blocking sleep.
     * 
     * @param message The message content to be sent.
     * @param room Pointer to the ChatRoom where the message should be sent.
     * @param delaySeconds Number of seconds to wait before sending (default is 0).
     */
    void sendDelayedMessage(const std::string& message, ChatRoom* room, int delaySeconds = 0);
};

#endif // NAME2_H