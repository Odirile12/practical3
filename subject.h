#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <vector>

class Observer;
class User;
class ChatRoom;

class Subject {
protected:
    std::vector<Observer*> observers;
public:
    Subject() = default;
    virtual ~Subject() = default;
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify(const std::string& message, User* fromUser, ChatRoom* room);
};

#endif