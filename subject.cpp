#include "Subject.h"
#include "Observer.h"


    void Subject::attach(Observer* observer) {
        observers.push_back(observer);
    }
    
    void Subject::detach(Observer* observer) {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }
    
    void Subject::notify(const std::string& message, User* fromUser, ChatRoom* room) {
        for (Observer* observer : observers) {
            observer->update(message, fromUser, room);
        }
    }