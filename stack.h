#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <cstddef>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
  Stack() = default;
  ~Stack() = default;

  size_t size() const {
    const std::vector<T>& v = *this; 
    return v.size();
  }

  bool empty() const {
    const std::vector<T>& v = *this;
    return v.empty();
  }

  void push(const T& item) {
    std::vector<T>& v = *this;    
    v.push_back(item);
  }

  void pop() {
    std::vector<T>& v = *this;
    if (v.empty()) {
      throw std::underflow_error("pop() on empty stack");
    }
    v.pop_back();
  }

  const T& top() const {
    const std::vector<T>& v = *this;
    if (v.empty()) {
      throw std::underflow_error("top() on empty stack");
    }
    return v.back();
  }
};


#endif