#ifndef NOTIFICATIONSERVICE_H
#define NOTIFICATIONSERVICE_H

/**
 * @class NotificationService
 * @brief The NotificationService class acts as an observer to receive notifications from the ChatRoom.
 *
 * This class implements the Observer pattern, allowing it to be notified of changes in the ChatRoom.
 */
class NotificationService {
public:
    /**
     * @brief Receives a notification from the ChatRoom.
     * @param message The message to be notified about.
     */
    void notify(const std::string& message);
};

#endif // NOTIFICATION_SERVICE_H