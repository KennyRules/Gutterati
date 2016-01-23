#pragma once

template <typename T>
class LinkedList
{
    public:
        virtual void add(T aValue) = 0;
        virtual void remove(T aValue) = 0;
        virtual T find(T aValue) const = 0;
        virtual int size() const = 0;
};