#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"
#include "userIterator.h"
#include "messageIterator.h"

/**
 * @class Dogorithm
 * @brief A specialized ChatRoom focused on algorithmic discussions and sessions.
 * 
 * Implements all core chat room functionalities including user management,
 * message handling, and history tracking. Also supports iteration over users
 * and messages using custom iterators.
 */
class Dogorithm : public ChatRoom {
public:
    /**
     * @brief Constructs the Dogorithm chat room with default settings.
     */
    Dogorithm();

    /**
     * @brief Virtual destructor for safe polymorphic cleanup.
     */
    virtual ~Dogorithm() = default;

    /**
     * @brief Registers a user to the Dogorithm room.
     * @param user Pointer to the User to be added.
     */
    void registerUser(User* user) override;

    /**
     * @brief Removes a user from the Dogorithm room.
     * @param user Pointer to the User to be removed.
     */
    void removeUser(User* user) override;

    /**
     * @brief Sends a message from a user to all other users in the room.
     * @param message The message content.
     * @param fromUser Pointer to the User sending the message.
     */
    void sendMessage(const std::string& message, User* fromUser) override;

    /**
     * @brief Saves a message to the Dogorithm room's history.
     * @param message The message content.
     * @param fromUser Pointer to the User who sent the message.
     */
    void saveMessage(const std::string& message, User* fromUser) override;

    /**
     * @brief Creates an iterator for traversing users in the room.
     * @return Pointer to a myIterator object for User pointers.
     */
    myIterator<User*>* createUserIterator() override;

    /**
     * @brief Creates an iterator for traversing messages in the room's history.
     * @return Pointer to a myIterator object for message strings.
     */
    myIterator<std::string>* createMessageIterator() override;

    /**
     * @brief Retrieves the list of users currently in the room.
     * @return Constant reference to the vector of User pointers.
     */
    const std::vector<User*>& getUsers() const override;

    /**
     * @brief Retrieves the chat history of the room.
     * @return Constant reference to the list of message strings.
     */
    const std::list<std::string>& getChatHistory() const override;

private:
    /**
     * @brief Describes the algorithmic focus or theme of the room.
     */
    std::string algorithmFocus;

    /**
     * @brief List of scheduled discussion or coding sessions.
     */
    std::vector<std::string> scheduledSessions;
};

#endif // DOGORITHM_H