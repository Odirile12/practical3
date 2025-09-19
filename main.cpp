#include <iostream>
#include "common.h"
#include "mediator/chat_room.h"
#include "mediator/ctrl_cat.h"
#include "mediator/dogorithm.h"
#include "user/normal_user.h"

int main() {
    // Create instances of the concrete mediators
    ChatRoom* ctrlCat = new CtrlCat();
    ChatRoom* dogorithm = new Dogorithm();

    // Create normal users
    NormalUser* user1 = new NormalUser("Alice", ctrlCat);
    NormalUser* user2 = new NormalUser("Bob", dogorithm);

    // Simulate sending messages
    user1->sendMessage("Hello, Bob!");
    user2->sendMessage("Hi, Alice!");

    // Clean up
    delete user1;
    delete user2;
    delete ctrlCat;
    delete dogorithm;

    return 0;
}