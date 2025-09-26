#ifndef OBSERVER_H
#define OBSERVER_H

#include "User.h"
#include "ChatRoom.h"
#include <string>

class User;
class ChatRoom;

/**
 * @class Observer
 * @brief Abstract base class for implementing the Observer pattern in chat rooms.
 * 
 * Observers are notified when a new message is sent in a chat room.
 * Concrete subclasses must implement the update method to define custom behavior.
 */
class Observer {
public:
    /**
     * @brief Virtual destructor for safe polymorphic cleanup.
     */
    virtual ~Observer() = default;

    /**
     * @brief Called when a new message is sent in a chat room.
     * 
     * Allows observers to react to message events, such as displaying notifications
     * or logging activity.
     * 
     * @param message The message content that triggered the update.
     * @param fromUser Pointer to the User who sent the message.
     * @param room Pointer to the ChatRoom where the message was sent.
     */
    virtual void update(const std::string& message, User* fromUser, ChatRoom* room) = 0;
};

#endif // OBSERVER_H