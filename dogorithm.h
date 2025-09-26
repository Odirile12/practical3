// #ifndef DOGORITHM_H
// #define DOGORITHM_H

// #include "ChatRoom.h" // Add this line to include the definition of ChatRoom

// /**
//  * @class Dogorithm
//  * @brief Concrete mediator that facilitates communication between users.
//  *
//  * The Dogorithm class implements the ChatRoom interface and manages the
//  * interactions between users in the chat system. It handles message
//  * exchanges and user registrations.
//  */
// class Dogorithm : public ChatRoom {
// public:

//     /**
//      * @brief Adds a user to the chat room.
//      * @param user The user to be added.
//      */
//     void registerUser(User* user) override;

//     /**
//      * @brief Sends a message from one user to another.
//      * @param sender The user sending the message.
//      * @param message The message content.
//      */    
//     void sendMessage(const std::string& message, User* fromUser) override;

//     /**
//      * @brief Removes a user from the chat room.
//      * @param user The user to be removed.
//      */
//     void removeUser(User* user) override;

//     /**
//      * @brief Saves a message to the chat history.
//      * @param message The message content.
//      * @param fromUser The user who sent the message.
//      */
//     void saveMessage(const std::string& message, User* fromUser) override;

//     /**
//      * @brief Default constructor for Dogorithm.
//      */
//     Dogorithm() = default;
//     /**
//      * @brief Destructor for Dogorithm.
//      */
//     ~Dogorithm() = default;
// };

// #endif // DOGORITHM_H

// #ifndef DOGORITHM_H
// #define DOGORITHM_H

// #include "ChatRoom.h" 
// #include "userIterator.h"

// class Dogorithm : public ChatRoom {
// public:
//     Dogorithm();
//     void registerUser(User* user) override ;
//     void removeUser(User* user) override;
//     myIterator<User*>* createUserIterator() override;
//     myIterator<std::string>* createMessageIterator() override;


// };

// #endif

#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h" 
#include "userIterator.h"
#include "messageIterator.h"

class Dogorithm : public ChatRoom {
public:
    Dogorithm();
    virtual ~Dogorithm() = default;
    
    void registerUser(User* user) override;
    void removeUser(User* user) override;
    void sendMessage(const std::string& message, User* fromUser) override;
    void saveMessage(const std::string& message, User* fromUser) override;
    
    myIterator<User*>* createUserIterator() override;
    myIterator<std::string>* createMessageIterator() override;
    
    const std::vector<User*>& getUsers() const override;
    const std::list<std::string>& getChatHistory() const override;
    

private:
    std::string algorithmFocus;
    std::vector<std::string> scheduledSessions;
};

#endif // DOGORITHM_H