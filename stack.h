#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack() : std::vector<T>() {};

    ~Stack() = default;

    bool empty() const {
      return std::vector<T>::empty();
    }

    size_t size() const {
      return std::vector<T>::size();
    }

    void push(const T& item) {
      this->push_back(item);
    }

    void pop() {
      if (empty()) {
        throw std::underflow_error("Stack is empty");
      }
      this->pop_back();
    } // throws std::underflow_error if empty

  
 
    //
    const T& top() const {

      if (empty()) {
        throw std::underflow_error("Stack is empty");
      }
      return this->back();
        
    } // throws std::underflow_error if empty
    // Add other members only if necessary
};


#endif
