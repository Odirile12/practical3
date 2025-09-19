#ifndef CTRLCAT_H
#define CTRLCAT_H

/**
 * @class CtrlCat
 * @brief Concrete mediator that manages user interactions in the chat room.
 *
 * The CtrlCat class implements the ChatRoom interface and facilitates communication
 * between users by managing their interactions and messages.
 */
class CtrlCat : public ChatRoom {
public:
    /**
     * @brief Default constructor for CtrlCat.
     */
    CtrlCat();

    /**
     * @brief Sends a message from one user to another.
     * @param sender The user sending the message.
     * @param message The message content.
     */
    void sendMessage(User* sender, const std::string& message);

    /**
     * @brief Adds a user to the chat room.
     * @param user The user to be added.
     */
    void addUser(User* user);

    /**
     * @brief Removes a user from the chat room.
     * @param user The user to be removed.
     */
    void removeUser(User* user);

    /**
     * @brief Notifies all users in the chat room of a new message.
     * @param message The message content.
     */
    void notifyUsers(const std::string& message);

private:
    std::vector<User*> users; ///< List of users in the chat room.
};

#endif // CTRL_CAT_H