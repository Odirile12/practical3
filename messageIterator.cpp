#include "messageIterator.h"

MessageIterator::MessageIterator(const std::list<std::string>& messageList) 
    : messages(messageList), currentPosition(messages.begin()) {}

bool MessageIterator::hasNext()   {
    return currentPosition != messages.end();
}

std::string MessageIterator::next()  {
    if (!hasNext()) {
        return "";
    }
    std::string message = *currentPosition;
    ++currentPosition;
    return message;
}

void MessageIterator::reset()  {
    currentPosition = messages.begin();
}