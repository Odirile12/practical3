#ifndef ADMIN_USER_H
#define ADMIN_USER_H

#include "User.h"

/**
 * @class AdminUser
 * @brief A specialized User with administrative privileges in a chat room.
 * 
 * Inherits from the base User class and overrides messaging behavior to include
 * administrative formatting. AdminUser can send and receive messages with elevated context.
 */
class AdminUser : public User {
public:
    /**
     * @brief Constructs an AdminUser with a given name.
     * @param name The name assigned to the admin user.
     */
    AdminUser(const std::string& name);
    
    /**
     * @brief Sends a message to a chat room with an [ADMIN] prefix.
     * 
     * Overrides the base User's send method to include administrative tagging.
     * Only sends the message if the user is part of the specified chat room.
     * 
     * @param message The message content to send.
     * @param room Pointer to the ChatRoom where the message should be sent.
     */
    void send(const std::string& message, ChatRoom* room) override;

    /**
     * @brief Receives a message from another user in a chat room.
     * 
     * Overrides the base User's receive method to display the message with
     * admin-specific formatting, including sender and room details.
     * 
     * @param message The message content received.
     * @param fromUser Pointer to the User who sent the message.
     * @param room Pointer to the ChatRoom where the message was received.
     */
    void receive(const std::string& message, User* fromUser, ChatRoom* room) override;
};

#endif // ADMIN_USER_H