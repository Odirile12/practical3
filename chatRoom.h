#ifndef CHATROOM_H
#define CHATROOM_H

#include "Subject.h"
#include <string>
#include <vector>
#include <list>

class User;
template <typename T> class myIterator;

/**
 * @class ChatRoom
 * @brief Abstract base class representing a chat room that manages users and message history.
 * 
 * Inherits from Subject to support observer notifications. Provides an interface for
 * registering users, sending and saving messages, and accessing chat history.
 */
class ChatRoom : public Subject {
protected:
    /**
     * @brief The name of the chat room.
     */
    std::string name;

    /**
     * @brief List of users currently in the chat room.
     */
    std::vector<User*> users;

    /**
     * @brief History of messages exchanged in the chat room.
     */
    std::list<std::string> chatHistory;
    std::vector<Observer*> observers;

public:
    /**
     * @brief Constructs a ChatRoom with a given name.
     * @param roomName The name assigned to the chat room.
     */
    ChatRoom(const std::string& roomName);
    
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notify(const std::string& message, User* fromUser, ChatRoom* room);

    /**
     * @brief Virtual destructor for safe polymorphic cleanup.
     */
    virtual ~ChatRoom() = default;

    /**
     * @brief Retrieves the name of the chat room.
     * @return The name of the chat room as a string.
     */
    std::string getName() const { return name; }

    /**
     * @brief Registers a user to the chat room.
     * @param user Pointer to the User to be added.
     */
    virtual void registerUser(User* user) = 0;

    /**
     * @brief Removes a user from the chat room.
     * @param user Pointer to the User to be removed.
     */
    virtual void removeUser(User* user) = 0;

    /**
     * @brief Sends a message from a user to all other users in the chat room.
     * @param message The message content.
     * @param fromUser Pointer to the User sending the message.
     */
    virtual void sendMessage(const std::string& message, User* fromUser) = 0;

    /**
     * @brief Saves a message to the chat room's history.
     * @param message The message content.
     * @param fromUser Pointer to the User who sent the message.
     */
    virtual void saveMessage(const std::string& message, User* fromUser) = 0;

    /**
     * @brief Creates an iterator for traversing users in the chat room.
     * @return Pointer to a myIterator object for User pointers.
     */
    virtual myIterator<User*>* createUserIterator() = 0;

    /**
     * @brief Creates an iterator for traversing messages in the chat history.
     * @return Pointer to a myIterator object for message strings.
     */
    virtual myIterator<std::string>* createMessageIterator() = 0;

    /**
     * @brief Retrieves the list of users in the chat room.
     * @return Constant reference to the vector of User pointers.
     */
    virtual const std::vector<User*>& getUsers() const = 0;

    /**
     * @brief Retrieves the chat history of the room.
     * @return Constant reference to the list of message strings.
     */
    virtual const std::list<std::string>& getChatHistory() const = 0;
};

#endif // CHATROOM_H