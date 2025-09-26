#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <list>

class ChatRoom;
class Command;

/**
 * @class User
 * @brief Abstract base class representing a participant in the chat system.
 * 
 * Defines core user behavior including room membership management and command execution.
 * Subclasses must implement message sending and receiving logic.
 */
class User {
protected:
    /**
     * @brief The name of the user.
     */
    std::string name;

    /**
     * @brief List of chat rooms the user has joined.
     */
    std::vector<ChatRoom*> chatRooms;

    /**
     * @brief Queue of commands to be executed by the user.
     */
    std::list<Command*> commandQueue;

public:
    /**
     * @brief Constructs a User with a given name.
     * @param userName The name of the user.
     */
    User(const std::string& userName);

    /**
     * @brief Virtual destructor for safe polymorphic cleanup.
     */
    virtual ~User();

    // Getters

    /**
     * @brief Retrieves the user's name.
     * @return The name of the user.
     */
    std::string getName() const;

    /**
     * @brief Retrieves the list of chat rooms the user has joined.
     * @return A constant reference to the vector of ChatRoom pointers.
     */
    const std::vector<ChatRoom*>& getChatRooms() const;

    // Room management

    /**
     * @brief Joins the user to a chat room.
     * 
     * Registers the user with the room and adds it to the user's list.
     * Prevents duplicate entries.
     * 
     * @param room Pointer to the ChatRoom to join.
     */
    void joinRoom(ChatRoom* room);

    /**
     * @brief Removes the user from a chat room.
     * 
     * Unregisters the user and removes the room from the user's list.
     * 
     * @param room Pointer to the ChatRoom to leave.
     */
    void leaveRoom(ChatRoom* room);

    /**
     * @brief Checks if the user is currently in a given chat room.
     * @param room Pointer to the ChatRoom to check.
     * @return True if the user is in the room, false otherwise.
     */
    bool isInRoom(ChatRoom* room) const;

    // Command pattern methods

    /**
     * @brief Adds a command to the user's command queue.
     * @param cmd Pointer to the Command to be queued.
     */
    void addCommand(Command* cmd);

    /**
     * @brief Executes all commands in the user's command queue.
     * 
     * Runs each command and clears the queue.
     */
    void executeCommands();

    /**
     * @brief Clears the user's command queue without executing.
     * 
     * Deletes all queued commands and empties the queue.
     */
    void clearCommandQueue();

    // Pure virtual methods - must be implemented by child classes

    /**
     * @brief Sends a message to a chat room.
     * @param message The message content to be sent.
     * @param room Pointer to the ChatRoom where the message should be sent.
     */
    virtual void send(const std::string& message, ChatRoom* room) = 0;

    /**
     * @brief Receives a message from another user in a chat room.
     * @param message The message content received.
     * @param fromUser Pointer to the User who sent the message.
     * @param room Pointer to the ChatRoom where the message was received.
     */
    virtual void receive(const std::string& message, User* fromUser, ChatRoom* room) = 0;
};

#endif // USER_H