#ifndef NAME1_H
#define NAME1_H

#include "User.h"

/**
 * @class Name1
 * @brief A concrete implementation of User representing a specific participant named "Alice".
 * 
 * Overrides the send and receive methods to provide custom behavior using command objects.
 */
class Name1 : public User {
public:
    /**
     * @brief Constructs a Name1 user with the name "Alice".
     */
    Name1();

    /**
     * @brief Sends a message to a chat room using command-based execution.
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
};

#endif // NAME1_H