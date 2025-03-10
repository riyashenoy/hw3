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
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

// constructor
template<typename T>
Stack<T>::Stack()
{



}

// destructor
template<typename T>
Stack<T>::~Stack()
{


}

// empty
template<typename T>
bool Stack<T>::empty() const
{
    // checks if no items
    return std::vector<T>::empty();
}

// size
template<typename T>
size_t Stack<T>::size() const
{
    // gets num of items in the stack
    return std::vector<T>::size();
}

// push
template<typename T>
void Stack<T>::push(const T& item)
{
    // pushes an item to the top
    std::vector<T>::push_back(item);
}

// pop
template<typename T>
void Stack<T>::pop()
{
    if (std::vector<T>::empty()) {
        // throws error
        throw std::underflow_error("the stack is empty!");
    }
    else{
        // removes the top item 
        std::vector<T>::pop_back();
    }

}

// top
template<typename T>
const T& Stack<T>::top() const
{
    if (std::vector<T>::empty()) {
        // throws error
        throw std::underflow_error("the stack is empty!");
    }
    else{
        // returns top item
        return std::vector<T>::back();
    }
}


#endif