#ifndef MESSAGEITERATOR_H
#define MESSAGEITERATOR_H

#include "iterator.h"
#include <list>
#include <string>

/**
 * @class MessageIterator
 * @brief Concrete iterator for traversing a list of chat messages.
 * 
 * Implements the myIterator interface to provide sequential access
 * to messages stored in a std::list. Supports iteration and reset.
 */
class MessageIterator : public myIterator<std::string> {
private:
    /**
     * @brief The list of messages to iterate over.
     */
    std::list<std::string> messages;

    /**
     * @brief Iterator pointing to the current position in the message list.
     */
    typename std::list<std::string>::const_iterator currentPosition;

public:
    /**
     * @brief Constructs a MessageIterator with a given list of messages.
     * @param messageList The list of messages to iterate over.
     */
    MessageIterator(const std::list<std::string>& messageList);

    /**
     * @brief Checks if there are more messages to iterate over.
     * @return True if more messages are available, false otherwise.
     */
    bool hasNext() override;

    /**
     * @brief Resets the iterator to the beginning of the message list.
     */
    void reset() override;

    /**
     * @brief Retrieves the next message in the list.
     * @return The next message string.
     */
    std::string next() override;
};

#endif // MESSAGE_ITERATOR_H