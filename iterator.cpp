#include "iterator.h"

/**
 * @brief Checks if there are more elements to iterate over.
 * 
 * This default implementation always returns false.
 * Derived classes should override this method with actual logic.
 * 
 * @tparam T The type of elements being iterated.
 * @return false Always returns false in the base implementation.
 */
template<typename T>
bool myIterator<T>::hasNext() { return false; }

/**
 * @brief Retrieves the next element in the iteration.
 * 
 * This default implementation returns a default-constructed object.
 * Derived classes should override this method to return actual elements.
 * 
 * @tparam T The type of elements being iterated.
 * @return A default-constructed object of type T.
 */
template<typename T>
T myIterator<T>::next() { return T(); }

/**
 * @brief Resets the iterator to the beginning.
 * 
 * This default implementation does nothing.
 * Derived classes should override this method to reset internal state.
 * 
 * @tparam T The type of elements being iterated.
 */
template<typename T>
void myIterator<T>::reset() {}