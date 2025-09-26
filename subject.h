#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <vector>

class Observer;
class User;
class ChatRoom;

/**
 * @class Subject
 * @brief Abstract base class for managing observers in the chat system.
 * 
 * Implements the core logic of the Observer design pattern, allowing observers
 * to subscribe to updates and be notified when events occur (e.g., new messages).
 */
class Subject {
protected:
    /**
     * @brief List of observers subscribed to this subject.
     */
    std::vector<Observer*> observers;

public:
    /**
     * @brief Default constructor.
     */
    Subject() = default;

    /**
     * @brief Virtual destructor for safe polymorphic cleanup.
     */
    virtual ~Subject() = default;

    /**
     * @brief Attaches an observer to the subject.
     * 
     * Adds the observer to the internal list so it can receive notifications.
     * 
     * @param observer Pointer to the Observer to be attached.
     */
    void attach(Observer* observer);

    /**
     * @brief Detaches an observer from the subject.
     * 
     * Removes the observer from the internal list to stop receiving notifications.
     * 
     * @param observer Pointer to the Observer to be detached.
     */
    void detach(Observer* observer);

    /**
     * @brief Notifies all attached observers of a new message.
     * 
     * Calls the update method on each observer, passing the message, sender, and room.
     * 
     * @param message The message content that triggered the notification.
     * @param fromUser Pointer to the User who sent the message.
     * @param room Pointer to the ChatRoom where the message was sent.
     */
    void notify(const std::string& message, User* fromUser, ChatRoom* room);
};

#endif // SUBJECT_H