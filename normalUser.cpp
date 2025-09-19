#include "normalUser.h"
#include "command/command.h"
#include <iostream>

/**
 * @class NormalUser
 * @brief Represents a normal user in the chat system who can invoke commands.
 */

NormalUser::NormalUser(const std::string& name) : User(name) {}

/**
 * @brief Invokes the given command.
 * @param command The command to be executed.
 */
void NormalUser::invokeCommand(Command* command) {
    if (command) {
        command->execute();
    } else {
        std::cerr << "Command is null!" << std::endl;
    }
}