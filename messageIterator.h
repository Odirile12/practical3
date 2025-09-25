
#ifndef MESSAGEITERATOR_H
#define MESSAGEITERATOR_H

#include "iterator.h"
#include <list>
#include <string>

/**
 * @class MessageIterator
 * @brief An iterator for iterating over messages in the chat system.
 *
 * This class implements the Iterator interface and provides methods
 * to traverse through the collection of messages.
 */
class MessageIterator: public myIterator<std::string> {
private:
private:
    std::list<std::string> messages;
    typename std::list<std::string>::const_iterator currentPosition;

public:
    /**
     * @brief Constructs a MessageIterator.
     */
    MessageIterator(const std::list<std::string>& messageList);

    /**
     * @brief Moves to the next message in the collection.
     * @return true if there is a next message, false otherwise.
     */
    bool hasNext() override;

    void reset() override;

    /**
     * @brief Returns the current message.
     * @return The current message.
     */
    std::string next() override;

private:
    // Add necessary private members for iteration
};

#endif // MESSAGE_ITERATOR_H