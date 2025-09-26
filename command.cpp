#include "command.h"

/**
 * @brief Constructs a Command object with a target chat room, user, and message.
 * 
 * Initializes the command with the context needed to execute a messaging action.
 * 
 * @param room Pointer to the ChatRoom where the command will be executed.
 * @param user Pointer to the User who issued the command.
 * @param message The message content associated with the command.
 */
Command::Command(ChatRoom* room, User* user, const std::string message)
    : user(user), message(message), room(room) {}

/**
 * @brief Executes the command.
 * 
 * This base implementation does nothing. Derived classes should override this method
 * to define specific command behavior (e.g., sending a message, saving history).
 */
void Command::execute() {
    return;
}