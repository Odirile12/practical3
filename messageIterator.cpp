#include "messageIterator.h"

/**
 * @brief Constructs a MessageIterator for traversing a list of messages.
 * 
 * Initializes the iterator with a reference to the message list and sets
 * the current position to the beginning.
 * 
 * @param messageList The list of messages to iterate over.
 */
MessageIterator::MessageIterator(const std::list<std::string>& messageList) 
    : messages(messageList), currentPosition(messages.begin()) {}

/**
 * @brief Checks if there are more messages to iterate over.
 * 
 * @return True if the iterator has not reached the end of the list.
 */
bool MessageIterator::hasNext() {
    return currentPosition != messages.end();
}

/**
 * @brief Retrieves the next message in the list.
 * 
 * If there are no more messages, returns an empty string.
 * 
 * @return The next message string, or an empty string if at the end.
 */
std::string MessageIterator::next() {
    if (!hasNext()) {
        return "";
    }
    std::string message = *currentPosition;
    ++currentPosition;
    return message;
}

/**
 * @brief Resets the iterator to the beginning of the message list.
 */
void MessageIterator::reset() {
    currentPosition = messages.begin();
}