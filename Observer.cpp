#include "Observer.h"

/**
 * @brief Default implementation of the Observer update method.
 * 
 * This method is intended to be overridden by concrete observer classes
 * to react to message events in a chat room. The base implementation does nothing.
 * 
 * @param message The message content that triggered the update.
 * @param fromUser Pointer to the User who sent the message.
 * @param room Pointer to the ChatRoom where the message was sent.
 */
void Observer::update(const std::string& message, User* fromUser, ChatRoom* room) {
    // Base implementation intentionally left blank.
}