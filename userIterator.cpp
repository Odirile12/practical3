#include "userIterator.h"

UserIterator::UserIterator(const std::vector<User*>& userList) 
    : users(userList), currentPosition(0) {}

bool UserIterator::hasNext() {
    return currentPosition < users.size();
}

User* UserIterator::next()  {
    if (!hasNext()) {
        return nullptr;
    }
    return users[currentPosition++];
}

void UserIterator::reset() {
    currentPosition = 0;
}