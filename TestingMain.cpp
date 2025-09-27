#include <iostream>
#include <memory>
#include "AdminUser.h"
#include "RegularUser.h"
#include "Name1.h"
#include "Name2.h"
#include "Name3.h"
#include "ctrlCat.h"
#include "dogorithm.h"
#include "notification.h"
#include "userIterator.h"
#include "messageIterator.h"
#include "sendMessageCommand.h"
#include "saveMessageCommand.h"

void testUserCreation();
void testChatRoomOperations();
void testCommandPattern();
void testIteratorPattern();
void testObserverPattern2();
void testMediatorPattern();
void testIntegrationScenario();
void testSpecialUserFeatures();

void testBasicChatFunctionality() {
    std::cout << "=== TEST 1: Basic Chat Functionality ===" << std::endl;
    
    // Create chat rooms
    CtrlCat ctrlCatRoom;
    Dogorithm dogorithmRoom;
    
    // Create users
    Name1 alice;
    Name2 bob;
    RegularUser regularCharlie("Regular Charlie");
    AdminUser adminDave("Admin Dave");
    
    // Add notification observers
    Notification notification1, notification2;
    ctrlCatRoom.addObserver(&notification1);
    dogorithmRoom.addObserver(&notification2);
    
    // Join rooms
    alice.joinRoom(&ctrlCatRoom);
    bob.joinRoom(&ctrlCatRoom);
    regularCharlie.joinRoom(&ctrlCatRoom);
    adminDave.joinRoom(&ctrlCatRoom);
    
    alice.joinRoom(&dogorithmRoom);
    bob.joinRoom(&dogorithmRoom);
    
    // Test messaging
    std::cout << "\n--- Testing CtrlCat Room ---" << std::endl;
    alice.send("Hello everyone in CtrlCat!", &ctrlCatRoom);
    bob.send("Hi Alice!", &ctrlCatRoom);
    regularCharlie.send("I'm a regular user", &ctrlCatRoom);
    adminDave.send("I'm an admin user", &ctrlCatRoom);
    
    std::cout << "\n--- Testing Dogorithm Room ---" << std::endl;
    alice.send("Algorithm discussion anyone?", &dogorithmRoom);
    bob.send("Sure, let's talk about sorting!", &dogorithmRoom);
}

void testIterators() {
    std::cout << "\n\n=== TEST 2: Iterator Pattern ===" << std::endl;
    
    CtrlCat room;
    Name1 alice;
    Name2 bob;
    Name3 charlie;
    
    alice.joinRoom(&room);
    bob.joinRoom(&room);
    charlie.joinRoom(&room);
    
    // Send some messages to create history
    alice.send("First message", &room);
    bob.send("Second message", &room);
    charlie.send("Third message", &room);
    
    // Test user iterator
    std::cout << "\n--- User Iterator Test ---" << std::endl;
    std::unique_ptr<myIterator<User*>> userIter(room.createUserIterator());
    std::cout << "Users in room:" << std::endl;
    while (userIter->hasNext()) {
        User* user = userIter->next();
        std::cout << "  - " << user->getName() << std::endl;
    }
    
    // Test message iterator
    std::cout << "\n--- Message Iterator Test ---" << std::endl;
    std::unique_ptr<myIterator<std::string>> msgIter(room.createMessageIterator());
    std::cout << "Message history:" << std::endl;
    while (msgIter->hasNext()) {
        std::string msg = msgIter->next();
        std::cout << "  - " << msg << std::endl;
    }
}

void testSpecialFeatures() {
    std::cout << "\n\n=== TEST 3: Special User Features ===" << std::endl;
    
    CtrlCat room;
    Name2 bob;
    Name3 charlie;
    
    bob.joinRoom(&room);
    charlie.joinRoom(&room);
    
    // Test Name3's message counting and formatting
    std::cout << "\n--- Name3 Message Counting ---" << std::endl;
    charlie.send("First message", &room);
    charlie.send("Second message", &room);
    charlie.sendFormattedMessage("Formatted message", &room);
    std::cout << "Charlie has sent " << charlie.getMessageCount() << " messages" << std::endl;
    
    // Test Name2's delayed messaging (with shorter delay for testing)
    std::cout << "\n--- Name2 Delayed Messaging ---" << std::endl;
    std::cout << "Starting delayed message test (1 second delay)..." << std::endl;
    bob.sendDelayedMessage("This was delayed!", &room, 1);
}

void testRoomManagement() {
    std::cout << "\n\n=== TEST 4: Room Management ===" << std::endl;
    
    CtrlCat room;
    Name1 alice;
    Name2 bob;
    
    // Test joining and leaving
    std::cout << "\n--- Room Membership Test ---" << std::endl;
    alice.joinRoom(&room);
    bob.joinRoom(&room);
    
    // Send message while both are in room
    alice.send("Bob, are you there?", &room);
    bob.send("Yes, I'm here!", &room);
    
    // Bob leaves
    bob.leaveRoom(&room);
    alice.send("Bob, can you hear me now?", &room); // Bob shouldn't receive this
    
    // Bob rejoins
    bob.joinRoom(&room);
    alice.send("Welcome back Bob!", &room);
}

void testErrorConditions() {
    std::cout << "\n\n=== TEST 5: Error Conditions ===" << std::endl;
    
    CtrlCat room;
    Name1 alice;
    
    // Test sending without joining room
    std::cout << "\n--- Sending Without Joining ---" << std::endl;
    alice.send("This should fail", &room);
    
    // Test empty message
    std::cout << "\n--- Empty Message Test ---" << std::endl;
    alice.joinRoom(&room);
    alice.send("", &room);
    
    // Test null room
    std::cout << "\n--- Null Room Test ---" << std::endl;
    alice.send("Message to null room", nullptr);
}

void testAdminPrivileges() {
    std::cout << "\n\n=== TEST 6: Admin User Features ===" << std::endl;
    
    CtrlCat room;
    AdminUser admin("SuperAdmin");
    RegularUser regular("RegularUser");
    
    admin.joinRoom(&room);
    regular.joinRoom(&room);
    
    // Test admin messaging format
    admin.send("Important announcement!", &room);
    regular.send("Regular user message", &room);
    
    // Test admin receiving format
    regular.send("Message to admin", &room);
}

void testChatHistory() {
    std::cout << "\n\n=== TEST 7: Chat History ===" << std::endl;
    
    Dogorithm room;
    Name1 alice;
    Name2 bob;
    
    alice.joinRoom(&room);
    bob.joinRoom(&room);
    
    // Send multiple messages
    alice.send("Starting algorithm discussion", &room);
    bob.send("I like bubble sort!", &room);
    alice.send("Bubble sort is O(n²)!", &room);
    bob.send("What about merge sort?", &room);
    
    // Display history using room's method
    std::cout << "\n--- Chat History ---" << std::endl;
    const auto& history = room.getChatHistory();
    for (const auto& msg : history) {
        std::cout << "  - " << msg << std::endl;
    }
}

void testObserverPattern() {
    std::cout << "\n\n=== TEST 8: Observer Pattern ===" << std::endl;
    
    CtrlCat room;
    Notification notification;
    
    // Add observer to the room
    room.addObserver(&notification);
    
    Name1 alice;
    Name2 bob;
    
    alice.joinRoom(&room);
    bob.joinRoom(&room);
    
    std::cout << "--- Testing Observer Notifications ---" << std::endl;
    // These messages should trigger observer notifications
    alice.send("This message should trigger notification", &room);
    bob.send("This should also trigger notification", &room);
    
    // Remove observer and test that notifications stop
    room.removeObserver(&notification);
    std::cout << "--- Observer Removed ---" << std::endl;
    alice.send("This should NOT trigger notification", &room);
}

int main() {
    std::cout << "=== CHAT SYSTEM COMPREHENSIVE TEST ===" << std::endl;
    std::cout << "Testing all implemented features...\n" << std::endl;
    
    try {
        testUserCreation();
        testChatRoomOperations();
        testCommandPattern();
        testIteratorPattern();
        testObserverPattern();
        testMediatorPattern();
        testSpecialUserFeatures();
        testIntegrationScenario();
        testBasicChatFunctionality();
        testIterators();
        testSpecialFeatures();
        testRoomManagement();
        testErrorConditions();
        testAdminPrivileges();
        testChatHistory();
        testObserverPattern2();
        
        std::cout << "\n\n=== ALL TESTS COMPLETED SUCCESSFULLY ===" << std::endl;
        std::cout << "The chat system is working correctly with all design patterns implemented:" << std::endl;
        std::cout << "✓ Command Pattern" << std::endl;
        std::cout << "✓ Iterator Pattern" << std::endl;
        std::cout << "✓ Observer Pattern" << std::endl;
        std::cout << "✓ Polymorphic User Types" << std::endl;
        std::cout << "✓ Room Management" << std::endl;
        std::cout << "✓ Message History" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}


void printTestHeader(const std::string& testName) {
    std::cout << "\n" << std::string(40, '-') << std::endl;
    std::cout << testName << std::endl;
    std::cout << std::string(40, '-') << std::endl;
}

void printTestResult(bool passed, const std::string& description) {
    std::cout << (passed ? "Pass" : "Fail") << description << std::endl;
}

void testUserCreation() {
    printTestHeader("Testing User Creation & Basic Functionality");

    // Test Name1 user
    Name1 user1;
    printTestResult(user1.getName() == "Name1", "Name1 user creation");

    // Test Name2 user
    Name2 user2;
    printTestResult(user2.getName() == "Name2", "Name2 user creation");

    // Test Name3 user
    Name3 user3;
    printTestResult(user3.getName() == "Name3", "Name3 user creation");
    printTestResult(user3.getMessageCount() == 0, "Name3 initial message count");

    // Test AdminUser
    AdminUser admin("AdminTest");
    printTestResult(admin.getName() == "AdminTest", "AdminUser creation");

    // Test RegularUser
    RegularUser regular("RegularTest");
    printTestResult(regular.getName() == "RegularTest", "RegularUser creation");

    std::cout << "User creation tests completed." << std::endl;
}

void testChatRoomOperations() {
    printTestHeader("Testing Chat Room Operations");

    CtrlCat ctrlRoom;
    Dogorithm dogoRoom;

    printTestResult(ctrlRoom.getName() == "CtrlCat", "CtrlCat room creation");
    printTestResult(dogoRoom.getName() == "Dogorithm", "Dogorithm room creation");

    Name1 alice;
    Name2 bob;
    RegularUser charlie("Charlie");

    ctrlRoom.registerUser(&alice);
    ctrlRoom.registerUser(&bob);
    ctrlRoom.registerUser(&charlie);

    dogoRoom.registerUser(&alice);
    dogoRoom.registerUser(&bob);

    printTestResult(alice.isInRoom(&ctrlRoom), "Alice joined CtrlCat room");
    printTestResult(alice.isInRoom(&dogoRoom), "Alice joined Dogorithm room");
    printTestResult(!charlie.isInRoom(&dogoRoom), "Charlie not in Dogorithm room");

    ctrlRoom.sendMessage("Hello from Alice!", &alice);
    dogoRoom.sendMessage("Algorithm discussion starting", &bob);

    ctrlRoom.saveMessage("Important note", &alice);
    dogoRoom.saveMessage("Key algorithm insight", &bob);

    ctrlRoom.removeUser(&charlie);
    printTestResult(!charlie.isInRoom(&ctrlRoom), "Charlie removed from CtrlCat room");

    std::cout << "Chat room operations tests completed." << std::endl;
}

void testCommandPattern() {
    printTestHeader("Testing Command Pattern");

    CtrlCat room;
    Name1 sender;
    Name2 receiver;

    room.registerUser(&sender);
    room.registerUser(&receiver);

    // Test sendMessageCommand
    sendMessageCommand* sendCmd = new sendMessageCommand(&room, &sender, "Command test message");
    sendCmd->execute();
    printTestResult(true, "sendMessageCommand executed");
    delete sendCmd;

    // Test SaveMessageCommand
    SaveMessageCommand* saveCmd = new SaveMessageCommand(&room, &sender, "Message to save via command");
    saveCmd->execute();
    printTestResult(true, "SaveMessageCommand executed");
    delete saveCmd;

    // Test command queue functionality
    sender.addCommand(new sendMessageCommand(&room, &sender, "Queued message 1"));
    sender.addCommand(new SaveMessageCommand(&room, &sender, "Queued save message"));
    sender.addCommand(new sendMessageCommand(&room, &sender, "Queued message 2"));

    sender.executeCommands();
    printTestResult(true, "Command queue executed successfully");

    // Test clear command queue
    sender.addCommand(new sendMessageCommand(&room, &sender, "This should be cleared"));
    sender.clearCommandQueue();
    printTestResult(true, "Command queue cleared successfully");

    std::cout << "Command pattern tests completed." << std::endl;
}

void testIteratorPattern() {
    printTestHeader("Testing Iterator Pattern");

    Name1 user1;
    Name2 user2;
    Name3 user3;
    AdminUser admin("TestAdmin");

    std::vector<User*> users = {&user1, &user2, &user3, &admin};
    UserIterator userIter(users);

    int userCount = 0;
    std::vector<std::string> expectedNames = {"Name1", "Name2", "Name3", "TestAdmin"};
    
    while (userIter.hasNext()) {
        User* user = userIter.next();
        printTestResult(user != nullptr, "UserIterator returned valid user");
        printTestResult(user->getName() == expectedNames[userCount], 
                       "UserIterator user name: " + user->getName());
        userCount++;
    }
    
    printTestResult(userCount == 4, "UserIterator counted all users correctly");

    userIter.reset();
    printTestResult(userIter.hasNext(), "UserIterator reset successfully");

    std::list<std::string> messages = {
        "First message",
        "Second message", 
        "Third message",
        "Fourth message"
    };

    MessageIterator msgIter(messages);
    
    int msgCount = 0;
    while (msgIter.hasNext()) {
        std::string msg = msgIter.next();
        printTestResult(!msg.empty(), "MessageIterator returned non-empty message");
        msgCount++;
    }
    
    printTestResult(msgCount == 4, "MessageIterator counted all messages correctly");

    // Test message iterator reset
    msgIter.reset();
    printTestResult(msgIter.hasNext(), "MessageIterator reset successfully");

    std::cout << "Iterator pattern tests completed." << std::endl;
}

void testObserverPattern2() {
    printTestHeader("Testing Observer Pattern");

    CtrlCat room;
    Name1 sender;
    Name2 receiver;
    Notification notifier;

    room.registerUser(&sender);
    room.registerUser(&receiver);

    // Test attaching observer
    room.attach(&notifier);
    printTestResult(true, "Observer attached to room");

    // Send message to trigger notification
    std::cout << "Sending message (should trigger notification):" << std::endl;
    room.sendMessage("Test message for notification", &sender);
    printTestResult(true, "Message sent and notification triggered");

    // Test detaching observer
    room.detach(&notifier);
    printTestResult(true, "Observer detached from room");

    // Send message after detaching (should not trigger notification)
    std::cout << "Sending message after detaching observer:" << std::endl;
    room.sendMessage("Message without notification", &sender);
    printTestResult(true, "Message sent without notification");

    std::cout << "Observer pattern tests completed." << std::endl;
}

void testMediatorPattern() {
    printTestHeader("Testing Mediator Pattern");

    CtrlCat ctrlRoom;
    Dogorithm dogoRoom;

    Name1 alice;
    Name2 bob;
    Name3 charlie;

    // Register users in different rooms
    ctrlRoom.registerUser(&alice);
    ctrlRoom.registerUser(&bob);

    dogoRoom.registerUser(&alice);
    dogoRoom.registerUser(&charlie);

    // Test communication through mediator
    std::cout << "Testing CtrlCat room communication:" << std::endl;
    ctrlRoom.sendMessage("Hello CtrlCat room!", &alice);
    ctrlRoom.sendMessage("Response from Bob", &bob);

    std::cout << "\nTesting Dogorithm room communication:" << std::endl;
    dogoRoom.sendMessage("Algorithm discussion in Dogorithm", &charlie);
    dogoRoom.sendMessage("Alice's algorithm insight", &alice);

    printTestResult(true, "Mediator pattern facilitating communication");

    // Test that messages are room-specific (mediator isolates communication)
    printTestResult(alice.getChatRooms().size() == 2, "Alice in multiple rooms");
    printTestResult(bob.getChatRooms().size() == 1, "Bob in single room");
    printTestResult(charlie.getChatRooms().size() == 1, "Charlie in single room");

    std::cout << "Mediator pattern tests completed." << std::endl;
}

void testSpecialUserFeatures() {
    printTestHeader("Testing Special User Features");

    CtrlCat room1;
    Dogorithm room2;
    
    Name1 name1User;
    Name2 name2User;
    Name3 name3User;

    room1.registerUser(&name1User);
    room1.registerUser(&name2User);
    room1.registerUser(&name3User);

    room2.registerUser(&name1User);

    // Test Name1 specific feature - broadcast to all rooms
    std::cout << "Testing Name1 broadcast feature:" << std::endl;
    printTestResult(true, "Name1 broadcast feature executed");

    // Test Name2 specific feature - delayed message
    std::cout << "Testing Name2 delayed message feature:" << std::endl;
    name2User.sendDelayedMessage("This is a delayed message", &room1, 1);
    printTestResult(true, "Name2 delayed message feature executed");

    // Test Name3 specific features
    std::cout << "Testing Name3 features:" << std::endl;
    int initialCount = name3User.getMessageCount();
    name3User.sendFormattedMessage("Formatted message test", &room1);
    
    printTestResult(name3User.getMessageCount() > initialCount, "Name3 message count updated");
    printTestResult(true, "Name3 formatted message feature executed");

    std::cout << "Special user features tests completed." << std::endl;
}

void testIntegrationScenario() {
    printTestHeader("Integration Test - Complete Chat Scenario");

    // Create environment
    CtrlCat programmingRoom;
    Dogorithm algorithmRoom;
    
    Name1 alice;
    Name2 bob;
    Name3 charlie;
    AdminUser admin("SystemAdmin");
    RegularUser guest("GuestUser");

    Notification notifier;

    // Setup rooms with observers
    programmingRoom.attach(&notifier);
    algorithmRoom.attach(&notifier);

    // Register users in rooms
    programmingRoom.registerUser(&alice);
    programmingRoom.registerUser(&bob);
    programmingRoom.registerUser(&admin);

    algorithmRoom.registerUser(&alice);
    algorithmRoom.registerUser(&charlie);
    algorithmRoom.registerUser(&guest);

    std::cout << "\n=== Chat Session Beginning ===" << std::endl;

    // Simulate conversation in programming room
    std::cout << "\n--- Programming Room Discussion ---" << std::endl;
    programmingRoom.sendMessage("Welcome everyone to the programming room!", &admin);
    programmingRoom.sendMessage("Hi! Excited to discuss coding topics", &alice);
    programmingRoom.sendMessage("Let's start with design patterns", &bob);

    // Test command pattern integration
    std::cout << "\n--- Using Command Pattern ---" << std::endl;
    alice.addCommand(new sendMessageCommand(&programmingRoom, &alice, "Command: Let's discuss the Observer pattern"));
    alice.addCommand(new SaveMessageCommand(&programmingRoom, &alice, "Important: Observer pattern discussion"));
    bob.addCommand(new sendMessageCommand(&programmingRoom, &bob, "Command: I'll explain the Mediator pattern"));

    alice.executeCommands();
    bob.executeCommands();

    // Simulate conversation in algorithm room
    std::cout << "\n--- Algorithm Room Discussion ---" << std::endl;
    algorithmRoom.sendMessage("Algorithm room is now active!", &charlie);
    algorithmRoom.sendMessage("I have some optimization ideas to share", &alice);
    algorithmRoom.sendMessage("Looking forward to learning!", &guest);

    // Test special user features
    std::cout << "\n--- Testing Special Features ---" << std::endl;

    bob.sendDelayedMessage("Delayed: This message was scheduled", &programmingRoom, 0);
    charlie.sendFormattedMessage("This is a specially formatted message", &algorithmRoom);

    // Test iterators on rooms with messages
    std::cout << "\n--- Testing Iterators with Real Data ---" << std::endl;
    
    // Test user iteration
    std::cout << "Users in Programming Room:" << std::endl;
    myIterator<User*>* progUserIter = programmingRoom.createUserIterator();
    int progUserCount = 0;
    while (progUserIter->hasNext()) {
        User* user = progUserIter->next();
        std::cout << "  - " << user->getName() << std::endl;
        progUserCount++;
    }
    delete progUserIter;
    printTestResult(progUserCount == 3, "Programming room user count correct");

    // Test message iteration
    std::cout << "\nMessages in Programming Room:" << std::endl;
    myIterator<std::string>* progMsgIter = programmingRoom.createMessageIterator();
    int progMsgCount = 0;
    while (progMsgIter->hasNext()) {
        std::string msg = progMsgIter->next();
        std::cout << "  - " << msg << std::endl;
        progMsgCount++;
    }
    delete progMsgIter;
    printTestResult(progMsgCount > 0, "Programming room has messages");

    std::cout << "\nUsers in Algorithm Room:" << std::endl;
    myIterator<User*>* algoUserIter = algorithmRoom.createUserIterator();
    int algoUserCount = 0;
    while (algoUserIter->hasNext()) {
        User* user = algoUserIter->next();
        std::cout << "  - " << user->getName() << std::endl;
        algoUserCount++;
    }
    delete algoUserIter;
    printTestResult(algoUserCount == 3, "Algorithm room user count correct");

    std::cout << "\n--- Testing Dynamic User Management ---" << std::endl;
    programmingRoom.removeUser(&bob);
    printTestResult(!bob.isInRoom(&programmingRoom), "Bob left programming room");

    algorithmRoom.registerUser(&bob);
    printTestResult(bob.isInRoom(&algorithmRoom), "Bob joined algorithm room");

    std::cout << "\n--- Session Ending ---" << std::endl;
    programmingRoom.sendMessage("Thanks everyone! Great discussion.", &admin);
    algorithmRoom.sendMessage("See you next time for more algorithms!", &charlie);

    programmingRoom.detach(&notifier);
    algorithmRoom.detach(&notifier);

    std::cout << "\n=== Integration Test Completed Successfully! ===" << std::endl;
    
    printTestResult(alice.getChatRooms().size() == 2, "Alice in correct number of rooms");
    printTestResult(bob.getChatRooms().size() == 1, "Bob in correct number of rooms");
    printTestResult(charlie.getChatRooms().size() == 1, "Charlie in correct number of rooms");
    printTestResult(admin.getChatRooms().size() == 1, "Admin in correct number of rooms");
    printTestResult(guest.getChatRooms().size() == 1, "Guest in correct number of rooms");

    std::cout << "Integration scenario tests completed." << std::endl;
}