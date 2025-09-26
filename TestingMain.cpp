#include <iostream>
#include "Name1.h"
#include "Name2.h"
#include "Name3.h"
#include "AdminUser.h"
#include "RegularUser.h"
#include "ctrlCat.h"
#include "dogorithm.h"
#include "notification.h"
#include "sendMessageCommand.h"
#include "saveMessageCommand.h"
#include "userIterator.h"
#include "messageIterator.h"

int main() {
    std::cout << "=== Starting Comprehensive Test ===" << std::endl;

    CtrlCat programmingRoom;
    Dogorithm algorithmRoom;
    std::cout << "✓ Chat rooms created" << std::endl;

    Name1 alice;
    Name2 bob;
    Name3 charlie;
    AdminUser admin("Admin");
    RegularUser regular("Regular");
    std::cout << "✓ Users created" << std::endl;

    if (alice.getName() == "Alice") {
        std::cout << "✓ Name1 user created: " << alice.getName() << std::endl;
    }
    if (bob.getName() == "Bob") {
        std::cout << "✓ Name2 user created: " << bob.getName() << std::endl;
    }
    if (charlie.getName() == "Charlie") {
        std::cout << "✓ Name3 user created: " << charlie.getName() << std::endl;
    }

    Notification notifier;
    programmingRoom.attach(&notifier);
    algorithmRoom.attach(&notifier);
    std::cout << "✓ Notification observer attached" << std::endl;

    programmingRoom.registerUser(&alice);
    programmingRoom.registerUser(&bob);
    programmingRoom.registerUser(&admin);
    algorithmRoom.registerUser(&alice);
    algorithmRoom.registerUser(&charlie);
    algorithmRoom.registerUser(&regular);
    std::cout << "✓ Users registered in chat rooms" << std::endl;

    std::cout << "\n=== Testing Basic Messaging ===" << std::endl;
    programmingRoom.sendMessage("Hello everyone!", &alice);
    programmingRoom.sendMessage("Hi Alice!", &bob);
    algorithmRoom.sendMessage("Let's discuss algorithms", &charlie);

    std::cout << "\n=== Testing Admin Messages ===" << std::endl;
    admin.send("Important announcement!", &programmingRoom);

    std::cout << "\n=== Testing Regular User Messages ===" << std::endl;
    regular.send("Hello from regular user", &algorithmRoom);

    std::cout << "\n=== Testing Command Pattern ===" << std::endl;
    SendMessageCommand sendCmd(&programmingRoom, &alice, "Test message via command");
    sendCmd.execute();
    SaveMessageCommand saveCmd(&programmingRoom, &alice, "Message to save");
    saveCmd.execute();

    alice.addCommand(new SendMessageCommand(&programmingRoom, &alice, "Queued message 1"));
    alice.addCommand(new SendMessageCommand(&programmingRoom, &alice, "Queued message 2"));
    alice.executeCommands();

    std::cout << "\n=== Testing Iterators ===" << std::endl;
    myIterator<User*>* userIter = programmingRoom.createUserIterator();
    std::cout << "Users in programming room:" << std::endl;
    while (userIter->hasNext()) {
        User* user = userIter->next();
        std::cout << "  - " << user->getName() << std::endl;
    }
    delete userIter;

    myIterator<std::string>* msgIter = programmingRoom.createMessageIterator();
    std::cout << "Messages in programming room:" << std::endl;
    while (msgIter->hasNext()) {
        std::string msg = msgIter->next();
        std::cout << "  - " << msg << std::endl;
    }
    delete msgIter;

    std::cout << "\n=== Testing User Removal ===" << std::endl;
    programmingRoom.removeUser(&bob);
    alice.send("Bob, are you there?", &programmingRoom);

    programmingRoom.detach(&notifier);
    algorithmRoom.detach(&notifier);

    std::cout << "\n✓ All tests completed successfully!" << std::endl;
    return 0;
}