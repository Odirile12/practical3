#ifndef CTRLCAT_H
#define CTRLCAT_H

#include <string>
#include "chatRoom.h"

/**
 * @class CtrlCat
 * @brief Concrete mediator that manages user interactions in the chat room.
 *
 * The CtrlCat class implements the ChatRoom interface and facilitates communication
 * between users by managing their interactions and messages.
 */
class CtrlCat : public chatRoom {
public:
    void rgisterUser(User* u) override;
    void removeUser(User* u) override;

};

#endif // CTRL_CAT_H