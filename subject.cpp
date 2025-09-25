#include "subject.h"

    void subject::attach(Observer* observer) {
        observers.push_back(observer);
    }
    
    void subject::detach(Observer* observer) {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }
    
    void subject::notify(const std::string& message, User* fromUser, chatRoom* room) {
        for (Observer* observer : observers) {
            observer->update(message, fromUser, room);
        }
    }