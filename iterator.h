#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class myIterator {
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() = 0;
    virtual T next() = 0;
    virtual void reset() = 0;
};

#endif // ITERATOR_H