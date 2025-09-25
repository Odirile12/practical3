// #ifndef DOGORITHM_H
// #define DOGORITHM_H

// #include "chatRoom.h" // Add this line to include the definition of chatRoom

// /**
//  * @class Dogorithm
//  * @brief Concrete mediator that facilitates communication between users.
//  *
//  * The Dogorithm class implements the chatRoom interface and manages the
//  * interactions between users in the chat system. It handles message
//  * exchanges and user registrations.
//  */
// class Dogorithm : public chatRoom {
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

#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "chatRoom.h" 
#include "userIterator.h"

class Dogorithm : public chatRoom {
public:
    Dogorithm();
    void registerUser(User* user) override ;
    void removeUser(User* user) override;
    myIterator<User*>* createUserIterator() override;
    myIterator<std::string>* createMessageIterator() override;


};

#endif