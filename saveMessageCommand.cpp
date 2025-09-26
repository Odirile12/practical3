#include "saveMessageCommand.h"

void SaveMessageCommand::execute() {
    // Implementation for saving the message
    if(room == nullptr || user == nullptr) {
        return; // Safety check
    }
   room->saveMessage(message, user);
}

