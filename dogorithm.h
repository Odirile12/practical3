#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "chatRoom.h"

/**
 * @class Dogorithm
 * @brief Concrete mediator that facilitates communication between users.
 *
 * The Dogorithm class implements the ChatRoom interface and manages the
 * interactions between users in the chat system. It handles message
 * exchanges and user registrations.
 */

 class Dogorithm : public chatRoom {
public:
    void rgisterUser(User* u) override;
    void removeUser(User* u) override;
};

#endif // DOGORITHM_H