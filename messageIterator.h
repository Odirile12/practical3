// message_iterator.h

#ifndef MESSAGEITERATOR_H
#define MESSAGEITERATOR_H

/**
 * @class MessageIterator
 * @brief An iterator for iterating over messages in the chat system.
 *
 * This class implements the Iterator interface and provides methods
 * to traverse through the collection of messages.
 */
class MessageIterator {
public:
    /**
     * @brief Constructs a MessageIterator.
     */
    MessageIterator();

    /**
     * @brief Moves to the next message in the collection.
     * @return true if there is a next message, false otherwise.
     */
    bool hasNext();

    /**
     * @brief Returns the current message.
     * @return The current message.
     */
    Message* next();

private:
    // Add necessary private members for iteration
};

#endif // MESSAGE_ITERATOR_H