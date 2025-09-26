#include "User.h"
#include "ChatRoom.h"
#include "command.h"
#include <algorithm>
#include <iostream>

/**
 * @brief Constructs a User with a given name.
 * @param userName The name of the user.
 */
User::User(const std::string& userName) : name(userName) {}

/**
 * @brief Destructor for User.
 * 
 * Clears the command queue to release memory and clean up pending commands.
 */
User::~User() {
    clearCommandQueue();
}

/**
 * @brief Retrieves the name of the user.
 * @return The user's name.
 */
std::string User::getName() const {
    return name;
}

/**
 * @brief Retrieves the list of chat rooms the user has joined.
 * @return A constant reference to the vector of ChatRoom pointers.
 */
const std::vector<ChatRoom*>& User::getChatRooms() const {
    return chatRooms;
}

/**
 * @brief Joins the user to a chat room.
 * 
 * Adds the room to the user's list and registers the user with the room.
 * Prevents duplicate entries.
 * 
 * @param room Pointer to the ChatRoom to join.
 */
void User::joinRoom(ChatRoom* room) {
    if (!isInRoom(room)) {
        chatRooms.push_back(room);
        room->registerUser(this);
        std::cout << name << " joined " << room->getName() << std::endl;
    }
}

/**
 * @brief Removes the user from a chat room.
 * 
 * Erases the room from the user's list and unregisters the user from the room.
 * 
 * @param room Pointer to the ChatRoom to leave.
 */
void User::leaveRoom(ChatRoom* room) {
    auto it = std::find(chatRooms.begin(), chatRooms.end(), room);
    if (it != chatRooms.end()) {
        chatRooms.erase(it);
        room->removeUser(this);
        std::cout << name << " left " << room->getName() << std::endl;
    }
}

/**
 * @brief Checks if the user is currently in a given chat room.
 * @param room Pointer to the ChatRoom to check.
 * @return True if the user is in the room, false otherwise.
 */
bool User::isInRoom(ChatRoom* room) const {
    return std::find(chatRooms.begin(), chatRooms.end(), room) != chatRooms.end();
}

/**
 * @brief Adds a command to the user's command queue.
 * @param cmd Pointer to the Command to be queued.
 */
void User::addCommand(Command* cmd) {
    commandQueue.push_back(cmd);
}

/**
 * @brief Executes all commands in the user's command queue.
 * 
 * Runs each command and deletes it afterward. Clears the queue.
 */
void User::executeCommands() {
    for (Command* cmd : commandQueue) {
        cmd->execute();
        delete cmd;
    }
    commandQueue.clear();
}

/**
 * @brief Clears the user's command queue without executing.
 * 
 * Deletes all queued commands and empties the queue.
 */
void User::clearCommandQueue() {
    for (Command* cmd : commandQueue) {
        delete cmd;
    }
    commandQueue.clear();
}