#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "chatRoom.h"

/**
 * @class User
 * @brief Represents a user in the chat system.
 *
 * The User class serves as a base class for different types of users
 * in the chat application. It provides the basic functionalities
 * that all users should have.
 */

class User {
private:
    std::string name;
    std::vector  <chatRoom*> chat;

public:
    virtual ~User() = default;
    User(std::string name);
    /**
     * @brief Sends a message to the chat room.
     * @param message The message to be sent.
     */
    virtual void send(std::string message,chatRoom* room) = 0;
    std::string getName() const;
    void joinRoom(chatRoom* room);
    void leaveRoom(chatRoom* room);
    /**
     * @brief Receives a message from the chat room.
     * @param message The message received.
     */
    virtual void receive( std::string message,User* fromUser,chatRoom* room) = 0;


};

#endif // USER_H