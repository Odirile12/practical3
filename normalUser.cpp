#include "normalUser.h"
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
