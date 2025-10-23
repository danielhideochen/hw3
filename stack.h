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
    return static_cast<const std::vector<T>&>(*this).size();
  }

  bool empty() const {
    return static_cast<const std::vector<T>&>(*this).empty();
  }

  void push(const T& item) {
    static_cast<std::vector<T>&>(*this).push_back(item);
  }

  void pop() {
    auto& v = static_cast<std::vector<T>&>(*this);
    if (v.empty()) throw std::underflow_error("pop() on empty stack");
    v.pop_back();
  }

  const T& top() const {
    const auto& v = static_cast<const std::vector<T>&>(*this);
    if (v.empty()) throw std::underflow_error("top() on empty stack");
    return v.back();
  }
};


#endif