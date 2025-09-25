// // src/mediator/ctrl_cat.cpp

// #include "ctrlCat.h"
// #include <iostream>

// /**
//  * @brief Constructs a CtrlCat object.
//  */
// CtrlCat::CtrlCat() {
//     // Constructor implementation
// }
// /**
//  * @brief Sends a message from a user to the chat room.
//  * 
//  * @param user The user sending the message.
//  * @param message The message to be sent.
//  */
// void CtrlCat::sendMessage(const std::string& message, User* fromUser) {
//     // Implementation for sending a message
//     std::cout << "[CtrlCat] " << fromUser->getName() << " sends: " << message << std::endl;
//     saveMessage(message, fromUser);
//     for (User* user : users) {
//         if (user != fromUser) {
//             user->receive(message, fromUser, this);
//         }
//     }
// }

// /**
//  * @brief Adds a user to the chat room.
//  * @param user The user to be added.
//  */
// void CtrlCat::registerUser(User* user) {
//     // Implementation for registering a user

//     users.push_back(user);
//     std::cout << "[CtrlCat] " << "User registered.\n";
// }
// /**
//  * @brief Removes a user from the chat room.
//  *
//  * @param user The user to be removed.
//  */
// void CtrlCat::removeUser(User *user){
//     // Implementation for removing a user
//     users.remove(user);
//     std::cout << "[CtrlCat] " << "User removed.\n";
// }
// /**
//  * @brief Saves a message to the chat history.
//  * @param message The message content.
//  * @param fromUser The user who sent the message.
//  */
// void CtrlCat::saveMessage(const std::string& message, User* fromUser) {
//     // Implementation for saving a message
//     chatHistrory.push_back(fromUser->getName() + ": " + message);
//     std::cout << "[CtrlCat] " << "Message saved to history.\n";


// }

#include "ctrlCat.h"
#include <iostream>
#include <algorithm>
#include "messageIterator.h"
#include "userIterator.h"



CtrlCat::CtrlCat() : chatRoom("CtrlCat") {}

void CtrlCat::registerUser(User* user)  {
    users.push_back(user);
    std::cout << user->getName() << " joined CtrlCat" << std::endl;
}

void CtrlCat::removeUser(User* user)  {
    users.erase(std::remove(users.begin(), users.end(), user), users.end());
    std::cout << user->getName() << " left CtrlCat" << std::endl;
}

myIterator<User*>* CtrlCat::createUserIterator()  {
    return new UserIterator(users);
}

myIterator<std::string>* CtrlCat::createMessageIterator()  {
    return new MessageIterator(chatHistory);
}