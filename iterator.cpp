#include "iterator.h"


template<typename T>
bool myIterator<T>::hasNext() { return false; }

template<typename T>
T myIterator<T>::next() { return T(); }

template<typename T>
void myIterator<T>::reset() {}