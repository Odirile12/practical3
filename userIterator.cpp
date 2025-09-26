#include "userIterator.h"

/**
 * @brief Constructs a UserIterator with a list of users.
 * 
 * Initializes the internal user list and sets the iterator position to the beginning.
 * 
 * @param userList A vector of User pointers to iterate over.
 */
UserIterator::UserIterator(const std::vector<User*>& userList)
    : users(userList), currentPosition(0) {}

/**
 * @brief Checks if there are more users to iterate over.
 * @return True if there are remaining users, false otherwise.
 */
bool UserIterator::hasNext() {
    return currentPosition < users.size();
}

/**
 * @brief Retrieves the next user in the iteration.
 * 
 * Returns a pointer to the next User and advances the iterator.
 * If no users remain, returns nullptr.
 * 
 * @return Pointer to the next User, or nullptr if iteration is complete.
 */
User* UserIterator::next() {
    if (!hasNext()) {
        return nullptr;
    }
    return users[currentPosition++];
}

/**
 * @brief Resets the iterator to the beginning of the user list.
 */
void UserIterator::reset() {
    currentPosition = 0;
}