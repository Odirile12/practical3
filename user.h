#ifndef USER_H
#define USER_H
#include <string>
#include "command.h"
#include "chatRoom.h"
#include <vector>
#include "Observer.h"

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
    ~User() = default;

    /**
     * @brief Constructs a User object with the given name.
     * @param name The name of the user.
     */
    User(std::string name);

    /**
     * @brief Sends a message to the chat room.
     * @param message The message to be sent.
     */
    void send(const std::string& message, chatRoom* room);

    /**
     * @brief Receives a message from the chat room.
     * @param message The message received.
     */
    virtual void receive(const std::string& message, User* fromUser, chatRoom* room);

    /**
     * @brief Adds a command to the user's command queue.
     * @param command The command to be added.
     */
    void addCommand(Command* command);

    /**
     * @brief Executes all commands in the user's command queue.
     */
    void executeAll();

    /**
     * @brief Gets the name of the user.
     * @return The name of the user.
     */
    std::string getName() const { return name; }

    protected:
        std::string name; ///< The name of the user.
        std::vector<chatRoom*> chatRooms; ///< List of joined chat rooms.
        std::vector<Command*> commandQueue; ///< Pointer to the command associated with the user.
};

#endif // USER_H