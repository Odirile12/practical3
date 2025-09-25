#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include <list>

class chatRoom;
class Command;

// /**
//  * @class User
//  * @brief Represents a user in the chat system.
//  *
//  * The User class serves as a base class for different types of users
//  * in the chat application. It provides the basic functionalities
//  * that all users should have.
//  */

// class User {
// public:
//     ~User() = default;

//     /**
//      * @brief Constructs a User object with the given name.
//      * @param name The name of the user.
//      */
//     User(const std::string& userName);

//     /**
//      * @brief Sends a message to the chat room.
//      * @param message The message to be sent.
//      */
//     void send(const std::string& message, chatRoom* room);

//     /**
//      * @brief Receives a message from the chat room.
//      * @param message The message received.
//      */
//     virtual void receive(const std::string& message, User* fromUser, chatRoom* room);

//     /**
//      * @brief Adds a command to the user's command queue.
//      * @param command The command to be added.
//      */
//     void addCommand(Command* command);

//     /**
//      * @brief Executes all commands in the user's command queue.
//      */
//     void executeAll();

//     /**
//      * @brief Gets the name of the user.
//      * @return The name of the user.
//      */
//     std::string getName() const { return name; }

//     protected:
//         std::string name; ///< The name of the user.
//         std::vector<chatRoom*> chatRooms; ///< List of joined chat rooms.
//         std::vector<Command*> commandQueue; ///< Pointer to the command associated with the user.
// };

class User {
protected:
    std::string name;
    std::vector<chatRoom*> chatRooms;
    std::list<Command*> commandQueue;

public:
    User(const std::string& userName);
    virtual ~User();
    
    // Getters
    std::string getName() const;
    const std::vector<chatRoom*>& getChatRooms() const;
    
    // Room management
    void joinRoom(chatRoom* room);
    void leaveRoom(chatRoom* room);
    bool isInRoom(chatRoom* room) const;
    
    // Command pattern methods
    void addCommand(Command* cmd);
    void executeCommands();
    void clearCommandQueue();
    
    // Pure virtual methods - must be implemented by child classes
    virtual void send(const std::string& message, chatRoom* room) = 0;
    virtual void receive(const std::string& message, User* fromUser, chatRoom* room) = 0;
};

#endif // USER_H