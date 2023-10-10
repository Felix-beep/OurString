#include "technikumSTL/iterator.h"


namespace technikum
{
    iterator::iterator()
    {
    currentIndex = nullptr;
    }

    iterator::iterator(char* index)
    {
        currentIndex = index;
    }

    iterator::~iterator()
    {
        
    }

    char& iterator::operator*() const
    {
        return *currentIndex;
    }

    char* iterator::operator->() const
    {
        return currentIndex;
    }

    iterator& iterator::operator++()
    {
        ++currentIndex;
        return *this;
    }

    iterator iterator::operator++(int)
    {
        iterator temp = *this;
        ++currentIndex;
        return temp;
    }

    iterator& iterator::operator--()
    {
        --currentIndex;
        return *this;
    }

    iterator iterator::operator--(int)
    {
        iterator temp = *this;
        --currentIndex;
        return temp;
    }
        
    bool iterator::operator==(const iterator& other) const
    {
        return currentIndex == other.currentIndex;
    }

    bool iterator::operator!=(const iterator& other) const
    {
        return currentIndex != other.currentIndex;
    }
    
}