// message_iterator.cpp
#include "messageIterator.h"

// Constructor
MessageIterator::MessageIterator(MessageCollection* collection) 
    : collection(collection), index(0) {}

// Returns the current message
Message* MessageIterator::current() {
    return collection->getMessage(index);
}

// Moves to the next message
bool MessageIterator::next() {
    if (index < collection->count() - 1) {
        index++;
        return true;
    }
    return false;
}

// Checks if there are more messages
bool MessageIterator::hasNext() {
    return index < collection->count() - 1;
}

// Resets the iterator to the beginning
void MessageIterator::reset() {
    index = 0;
}