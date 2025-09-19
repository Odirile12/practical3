#ifndef NORMALUSER_H
#define NORMALUSER_H

/**
 * @class NormalUser
 * @brief Represents a normal user in the chat system.
 * 
 * The NormalUser class extends the User class and acts as the invoker for commands.
 * It allows users to send and save messages through the command interface.
 */

#include "user.h"

class NormalUser : public User {
public:
    NormalUser(const std::string& name);
    
    /**
     * @brief Sends a message using the SendMessageCommand.
     * @param message The message to be sent.
     */
    void sendMessage(const std::string& message);
    
    /**
     * @brief Saves a message using the SaveMessageCommand.
     * @param message The message to be saved.
     */
    void saveMessage(const std::string& message);
};

#endif // NORMAL_USER_H