#ifndef NAME3_H
#define NAME3_H

#include "User.h"

/**
 * @class Name3
 * @brief A concrete implementation of User representing a participant named "Charlie".
 * 
 * Tracks the number of messages sent and supports formatted message output.
 * Uses command objects to send and save messages.
 */
class Name3 : public User {
private:
    /**
     * @brief Counter for the number of messages sent by this user.
     */
    int messageCount;

public:
    /**
     * @brief Constructs a Name3 user with the name "Charlie".
     */
    Name3();

    /**
     * @brief Sends a message to a chat room using command-based execution.
     * 
     * Increments the message count and queues send/save commands.
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
     * @brief Retrieves the number of messages sent by this user.
     * @return The total message count.
     */
    int getMessageCount() const;

    /**
     * @brief Sends a formatted message with decorative tags and message count.
     * 
     * Prepends visual markers and includes the next message number.
     * 
     * @param message The raw message content to be formatted and sent.
     * @param room Pointer to the ChatRoom where the message should be sent.
     */
    void sendFormattedMessage(const std::string& message, ChatRoom* room);
};

#endif // NAME3_H#ifndef NAME3_H
