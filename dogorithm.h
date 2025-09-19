#ifndef DOGORITHM_H
#define DOGORITHM_H

/**
 * @class Dogorithm
 * @brief Concrete mediator that facilitates communication between users.
 *
 * The Dogorithm class implements the ChatRoom interface and manages the
 * interactions between users in the chat system. It handles message
 * exchanges and user registrations.
 */
class Dogorithm : public ChatRoom {
public:
    // Constructor
    Dogorithm();

    // Method to register a user
    void registerUser(User* user) override;

    // Method to send a message from one user to another
    void sendMessage(const std::string& message, User* sender, User* receiver) override;

    // Method to notify users of a new message
    void notifyUsers(const std::string& message, User* sender) override;

    // Destructor
    ~Dogorithm();
};

#endif // DOGORITHM_H