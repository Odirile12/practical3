
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
    std::list<std::string>* messages; // Pointer to the collection of messages
    int position;

public:
    /**
     * @brief Constructs a MessageIterator.
     */
    MessageIterator(std::list<std::string>* messages);

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