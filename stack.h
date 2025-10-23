#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack() = default;
    ~Stack() = default;

    size_t size() const {
        return Base::size();
    }

    bool empty() const {
        return Base::empty();
    }

    void push(const T& item) {
        Base::push_back(item);
    }

    void pop() {
        if (Base::empty()) {
            throw std::underflow_error("pop() on empty stack");
        }
        Base::pop_back();
    }

    const T& top() const {
        if (Base::empty()) {
            throw std::underflow_error("top() on empty stack");
        }
        return Base::back();
    }
};


#endif