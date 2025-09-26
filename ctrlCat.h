// #ifndef CTRLCAT_H
// #define CTRLCAT_H

// #include "ChatRoom.h" // Add this line to include the definition of ChatRoom
// #include <vector>

// /**
//  * @class CtrlCat
//  * @brief Concrete mediator that manages user interactions in the chat room.
//  *
//  * The CtrlCat a implements the ChatRoom interface and facilitates communication
//  * between users by managing their interactions and messages.
//  */
// class CtrlCat : public ChatRoom {
// public:
//     /**
//      * @brief Default constructor for CtrlCat.
//      */
//     CtrlCat() = default;
//     /**
//      * @brief Destructor for CtrlCat.
//      */
//     ~CtrlCat() = default;

//     /**
//      * @brief Sends a message from one user to another.
//      * @param sender The user sending the message.
//      * @param message The message content.
//      */
//     void sendMessage(const std::string& message, User* fromUser) override;

//     /**
//      * @brief Adds a user to the chat room.
//      * @param user The user to be added.
//      */
//     void registerUser(User* user) override;

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

// };

// #endif // CTRL_CAT_H

// #ifndef CTRLCAT_H
// #define CTRLCAT_H

// #include "ChatRoom.h"
// #include "userIterator.h"
// #include "messageIterator.h"

// class CtrlCat : public ChatRoom {
// public:
//     CtrlCat();
//     void registerUser(User* user) override;
//     void removeUser(User* user) override;
//     myIterator<User*>* createUserIterator() override;
//     myIterator<std::string>* createMessageIterator() override;
// };


// #endif // CTRL_CAT_H

#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"
#include "userIterator.h"
#include "messageIterator.h"

class CtrlCat : public ChatRoom {
public:
    CtrlCat();
    virtual ~CtrlCat() = default;
    
    void registerUser(User* user) override;
    void removeUser(User* user) override;
    void sendMessage(const std::string& message, User* fromUser) override;
    void saveMessage(const std::string& message, User* fromUser) override;
    
    myIterator<User*>* createUserIterator() override;
    myIterator<std::string>* createMessageIterator() override;
    
    const std::vector<User*>& getUsers() const override;
    const std::list<std::string>& getChatHistory() const override;

    
private:
    bool moderationEnabled;
    std::string roomTopic;
};

#endif // CTRLCAT_H

