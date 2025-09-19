// notification_service.cpp

#include "notificationService.h"

//! Constructor for NotificationService
NotificationService::NotificationService() {}

//! Method to receive notifications from the ChatRoom
void NotificationService::update(const std::string& message) {
    // Handle the received message
    std::cout << "Notification received: " << message << std::endl;
}