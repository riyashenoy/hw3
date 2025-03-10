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

private: 
    std::vector<T> stackVec;
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
    return stackVec.empty();
}

// size
template<typename T>
size_t Stack<T>::size() const
{
    // gets num of items in the stack
    return stackVec.size();
}

// push
template<typename T>
void Stack<T>::push(const T& item)
{
    // pushes an item to the top
    stackVec.push_back(item);
}

// pop
template<typename T>
void Stack<T>::pop()
{
    if(stackVec.empty())
    {
        throw std::underflow_error("the stack is empty!");
    }
    stackVec.pop_back();
}

// top
template<typename T>
const T& Stack<T>::top() const
{
    if(stackVec.empty())
    {
        throw std::underflow_error("the stack is empty!");
    }
    return stackVec[stackVec.size() - 1];
}


#endif