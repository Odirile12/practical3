#ifndef USERITERATOR_H
#define USERITERATOR_H

#include "user.h"
#include <list>
#include "iterator.h"


/**
 * @class UserIterator
 * @brief Iterator for iterating over users in the chat system.
 *
 * This class implements the Iterator interface to provide a way to access 
 * users in a sequential manner without exposing the underlying representation.
 */
class UserIterator : public myIterator<User*> {
private:
    std::list<User*> users; // Pointer to the collection of users
    int posution; // Current position in the iteration

public:
    UserIterator(std::list<User*> users);
    /**
     * @brief Advances the iterator to the next user.
     * @return true if there is a next user, false otherwise.
     */
    bool hasNext() override;

    /**
     * @brief Returns the next user in the iteration.
     * @return The next user.
     */
    User* next() override;

    /**
     * @brief Resets the iterator to the beginning.
     */
    void reset() override;

    ~UserIterator() = default; // Virtual destructor for proper cleanup
};

#endif // USER_ITERATOR_H