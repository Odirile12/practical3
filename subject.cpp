#include "Subject.h"
#include "Observer.h"

/**
 * @brief Attaches an observer to the subject.
 * 
 * Adds the observer to the internal list so it can receive future notifications.
 * 
 * @param observer Pointer to the Observer to be attached.
 */
void Subject::attach(Observer* observer) {
    observers.push_back(observer);
}

/**
 * @brief Detaches an observer from the subject.
 * 
 * Removes the observer from the internal list to stop receiving notifications.
 * 
 * @param observer Pointer to the Observer to be detached.
 */
void Subject::detach(Observer* observer) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            observers.erase(it);
            break;
        }
    }
}

/**
 * @brief Notifies all attached observers of a new message.
 * 
 * Iterates through the observer list and calls their update method,
 * passing along the message, sender, and chat room context.
 * 
 * @param message The message content that triggered the notification.
 * @param fromUser Pointer to the User who sent the message.
 * @param room Pointer to the ChatRoom where the message was sent.
 */
void Subject::notify(const std::string& message, User* fromUser, ChatRoom* room) {
    for (Observer* observer : observers) {
        observer->update(message, fromUser, room);
    }
}