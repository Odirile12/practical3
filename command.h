#ifndef COMMAND_H
#define COMMAND_H

/**
 * @brief Abstract Command class that defines the interface for command objects.
 */
class Command {
public:
    /**
     * @brief Executes the command.
     */
    virtual void execute() = 0;

    /**
     * @brief Destructor for the Command class.
     */
    virtual ~Command() {}
};

#endif // COMMAND_H