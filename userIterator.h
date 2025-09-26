#ifndef USERITERATOR_H
#define USERITERATOR_H

#include "User.h"
#include <vector>
#include "iterator.h"

/**
 * @class UserIterator
 * @brief Concrete iterator for traversing a collection of User pointers.
 * 
 * Implements the custom Iterator interface to provide sequential access
 * to users in a chat system without exposing the underlying container.
 */
class UserIterator : public myIterator<User*> {
private:
    /**
     * @brief Internal list of users to iterate over.
     */
    std::vector<User*> users;

    /**
     * @brief Current position in the user list.
     */
    size_t currentPosition;

public:
    /**
     * @brief Constructs a UserIterator with a given list of users.
     * @param userList A vector of User pointers to iterate over.
     */
    UserIterator(const std::vector<User*>& userList);

    /**
     * @brief Checks if there are more users to iterate over.
     * @return True if a next user exists, false otherwise.
     */
    bool hasNext() override;

    /**
     * @brief Retrieves the next user in the sequence.
     * @return Pointer to the next User, or nullptr if iteration is complete.
     */
    User* next() override;

    /**
     * @brief Resets the iterator to the beginning of the user list.
     */
    void reset() override;

    /**
     * @brief Virtual destructor for proper cleanup.
     */
    ~UserIterator() = default;
};

#endif // USER_ITERATOR_H