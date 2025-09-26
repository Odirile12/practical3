
#ifndef MESSAGEITERATOR_H
#define MESSAGEITERATOR_H

#include "iterator.h"
#include <list>
#include <string>

class MessageIterator: public myIterator<std::string> {
private:
private:
    std::list<std::string> messages;
    typename std::list<std::string>::const_iterator currentPosition;

public:

    MessageIterator(const std::list<std::string>& messageList);
    bool hasNext() override;
    void reset() override;
    std::string next() override;

};

#endif // MESSAGE_ITERATOR_H