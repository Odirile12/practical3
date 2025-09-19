# Chat Mediator App

This project implements a chat mediator system using the Mediator design pattern. The system allows users to communicate through a chat room, with commands to send and save messages. It also includes iterators for users and messages, and an observer for notifications.

## Project Structure

```
chat-mediator-app
├── src
│   ├── mediator
│   │   ├── chat_room.h
│   │   ├── chat_room.cpp
│   │   ├── ctrl_cat.h
│   │   ├── ctrl_cat.cpp
│   │   ├── dogorithm.h
│   │   └── dogorithm.cpp
│   ├── command
│   │   ├── command.h
│   │   ├── send_message_command.h
│   │   ├── send_message_command.cpp
│   │   ├── save_message_command.h
│   │   └── save_message_command.cpp
│   ├── iterator
│   │   ├── user_iterator.h
│   │   ├── user_iterator.cpp
│   │   ├── message_iterator.h
│   │   └── message_iterator.cpp
│   ├── observer
│   │   ├── notification_service.h
│   │   └── notification_service.cpp
│   ├── user
│   │   ├── user.h
│   │   ├── user.cpp
│   │   ├── normal_user.h
│   │   └── normal_user.cpp
│   ├── main.cpp
│   └── common.h
├── CMakeLists.txt
└── README.md
```

## Components

- **ChatRoom**: Abstract mediator interface for managing communication between users.
- **CtrlCat**: Concrete mediator managing user interactions in the chat room.
- **Dogorithm**: Another concrete mediator facilitating communication between users.
- **SendMessageCommand**: Command for sending messages.
- **SaveMessageCommand**: Command for saving messages.
- **NormalUser**: Invoker for commands.
- **UserIterator**: Iterator for iterating over users.
- **MessageIterator**: Iterator for iterating over messages.
- **NotificationService**: Observer for receiving notifications from the ChatRoom.

## Build Instructions

To build the project, use CMake:

1. Navigate to the project directory.
2. Run `cmake .` to configure the project.
3. Run `make` to build the project.

## Usage

After building the project, run the executable to start the chat mediator application. Users can send and save messages through the provided commands.