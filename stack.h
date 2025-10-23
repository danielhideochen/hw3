#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack();
    ~Stack();
  // O(1)
  size_t size() const { return std::vector<T>::size(); }

  // O(1)
  bool empty() const { return std::vector<T>::empty(); }

  // O(1) — push to top
  void push(T const& item) { std::vector<T>::push_back(item); }

  // O(1) — remove top; throw if empty
  void pop() {
    if (std::vector<T>::empty()) {
      throw std::underflow_error("pop() on empty stack");
    }
    std::vector<T>::pop_back();
  }

  // O(1) — view top; throw if empty
  T const& top() const {
    if (std::vector<T>::empty()) {
      throw std::underflow_error("top() on empty stack");
    }
    return std::vector<T>::back();
  }

};


#endif