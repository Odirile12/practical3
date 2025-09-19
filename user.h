#ifndef USER_H
#define USER_H

/**
 * @class User
 * @brief Represents a user in the chat system.
 *
 * The User class serves as a base class for different types of users
 * in the chat application. It provides the basic functionalities
 * that all users should have.
 */
class User {
public:
    virtual ~User() = default;

    /**
     * @brief Sends a message to the chat room.
     * @param message The message to be sent.
     */
    virtual void sendMessage(const std::string& message) = 0;

    /**
     * @brief Receives a message from the chat room.
     * @param message The message received.
     */
    virtual void receiveMessage(const std::string& message) = 0;
};

#endif // USER_H