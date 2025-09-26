#ifndef ITERATOR_H
#define ITERATOR_H

/**
 * @brief Generic iterator interface for traversing collections of type T.
 * 
 * This abstract class defines the core operations for iteration:
 * checking for remaining elements, retrieving the next element, and resetting the iterator.
 * Concrete subclasses must implement these methods to provide actual traversal logic.
 * 
 * @tparam T The type of elements to iterate over.
 */
template <typename T>
class myIterator {
public:
    /**
     * @brief Virtual destructor for safe polymorphic cleanup.
     */
    virtual ~myIterator() = default;

    /**
     * @brief Checks if there are more elements to iterate over.
     * @return True if more elements are available, false otherwise.
     */
    virtual bool hasNext() = 0;

    /**
     * @brief Retrieves the next element in the iteration.
     * @return The next element of type T.
     */
    virtual T next() = 0;

    /**
     * @brief Resets the iterator to the beginning of the collection.
     */
    virtual void reset() = 0;
};

#endif // ITERATOR_H