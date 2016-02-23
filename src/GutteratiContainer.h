#pragma once

#include <stdexcept>

/// GutteratiContainer is the top-level abstract class for all Gutterati 
/// containers and provides a simple interface and implementation details
/// for operations common to all containers.
class GutteratiContainer
{
    public:
        inline size_t getSize() const noexcept;
        inline bool isEmpty() const noexcept;

        /// Clears the data this GutteratiContainer is holding.
        /// Implementations determine if this resets the size to 0 or not.
        virtual void clear() noexcept = 0;

    protected:
        size_t m_size = 0;
};

/// Gets total number of elements that are stored in this GutteratiContainer.
/// @return Total number of elements contained in this GutteratiContainer.
inline size_t GutteratiContainer::getSize() const noexcept 
{
    return m_size;
}

/// Helper function to quickly check if this GutteratiContainer is empty or not.
/// @return True if this container has 0 elements, false otherwise.
inline bool GutteratiContainer::isEmpty() const noexcept
{
    return m_size == 0;
}