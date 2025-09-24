// user.cpp

#include "user.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"
#include <iostream>

/**
 * @brief Constructs a User object with the given name.
 * @param name The name of the user.
 */
User::User(std::string name) : 
name(name) {};

/**
 * @brief Sends a message to the chat room.
 * @param message The message to be sent.
 */
void User::send(const std::string &message, chatRoom* room){

    std::cout << name << " sends: " << message << std::endl;
    room->sendMessage(message, this);

    addCommand(new SendMessageCommand(room, this, message));
    addCommand(new SaveMessageCommand(room, this, message));

    executeAll();
}
/**
 * @brief Receives a message from the chat room.
 * @param message The message received.
 */
void User::receive(const std::string &message, User* fromUser, chatRoom* room){

    std::cout << name << " received from " << fromUser->name << ": " << message << std::endl;
}
/**
 * @brief Adds a command to the user's command queue.
 * @param command The command to be added.
 */
void User::addCommand(Command *command)
{
    commandQueue.push_back(command);
};

/**
 * @brief Executes all commands in the user's command queue.
 */
void User::executeAll(){
    for (Command* command : commandQueue) {
        if(command) {
            command->execute();
        }
    }
    commandQueue.clear(); // Clear the queue after executing all commands
};
