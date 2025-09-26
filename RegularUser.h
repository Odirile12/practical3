#ifndef REGULAR_USER_H
#define REGULAR_USER_H

#include "User.h"

/**
 * @class RegularUser
 * @brief A basic implementation of the User class representing a standard chat participant.
 * 
 * RegularUser interacts with chat rooms by sending and receiving messages directly,
 * without command queuing or advanced features. Includes a placeholder status field.
 */
class RegularUser : public User {
public:
    /**
     * @brief Constructs a RegularUser with a given name.
     * @param name The name of the user.
     */
    RegularUser(const std::string& name);

    /**
     * @brief Sends a message to a chat room.
     * 
     * Validates room membership and delegates message dispatch to the ChatRoom.
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

private:
    /**
     * @brief Optional status field for future user state tracking.
     */
    std::string userStatus;
};

#endif // REGULAR_USER_H