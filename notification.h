#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include "Observer.h"
#include <iostream>
#include <string>

/**
 * @class Notification
 * @brief Concrete observer that reacts to chat room message updates.
 * 
 * Implements the Observer interface to receive notifications when a new message
 * is sent in a chat room. Displays formatted output to the console.
 */
class Notification : public Observer {
public:
    /**
     * @brief Default constructor for Notification.
     */
    Notification() = default;

    /**
     * @brief Handles updates triggered by chat room activity.
     * 
     * Displays a notification message including the room name, sender, and content.
     * 
     * @param message The message content that triggered the update.
     * @param fromUser Pointer to the User who sent the message.
     * @param room Pointer to the ChatRoom where the message was sent.
     */
    void update(const std::string& message, User* fromUser, ChatRoom* room) override;
};

#endif // NOTIFICATION_H