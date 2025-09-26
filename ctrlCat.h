#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"
#include "userIterator.h"
#include "messageIterator.h"

/**
 * @class CtrlCat
 * @brief Concrete implementation of a ChatRoom named "CtrlCat".
 * 
 * Manages user registration, message delivery, and chat history.
 * Supports iteration over users and messages via custom iterators.
 */
class CtrlCat : public ChatRoom {
public:
    /**
     * @brief Constructs the CtrlCat chat room with default settings.
     */
    CtrlCat();

    /**
     * @brief Virtual destructor for safe polymorphic cleanup.
     */
    virtual ~CtrlCat() = default;

    /**
     * @brief Registers a user to the CtrlCat room.
     * @param user Pointer to the User to be added.
     */
    void registerUser(User* user) override;

    /**
     * @brief Removes a user from the CtrlCat room.
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
     * @brief Saves a message to the CtrlCat room's history.
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
     * @brief Flag indicating whether moderation features are enabled.
     */
    bool moderationEnabled;

    /**
     * @brief Topic or description of the chat room.
     */
    std::string roomTopic;
};

#endif // CTRLCAT_H