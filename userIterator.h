// user_iterator.h
#ifndef USERITERATOR_H
#define USERITERATOR_H

/**
 * @class UserIterator
 * @brief Iterator for iterating over users in the chat system.
 *
 * This class implements the Iterator interface to provide a way to access 
 * users in a sequential manner without exposing the underlying representation.
 */
class UserIterator {
public:
    /**
     * @brief Advances the iterator to the next user.
     * @return true if there is a next user, false otherwise.
     */
    virtual bool hasNext() = 0;

    /**
     * @brief Returns the next user in the iteration.
     * @return The next user.
     */
    virtual User* next() = 0;

    /**
     * @brief Resets the iterator to the beginning.
     */
    virtual void reset() = 0;

    virtual ~UserIterator() = default; // Virtual destructor for proper cleanup
};

#endif // USER_ITERATOR_H