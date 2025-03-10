#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  
  // stores heap itesm
  std::vector<T> data; 
  
  // tracks m ary (# children for each node)
  int m;         
  
  // used to compare item to oena nother 
  PComparator comp;




};

// Add implementation of member functions here

// construcor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
  : m(m), comp(c){

}

// destructor
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {
}

// push
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  
  data.push_back(item);

  // new item index
  int index = data.size() - 1;

  // bubble up
  while(index > 0) {

    // parent index
    int parent_index = (index - 1) / m;

    if(comp(data[index], data[parent_index])) {

      std::swap(data[index], data[parent_index]);

      // go up the parents index
      index = parent_index;

    } 

    else {
      break;
    }

  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("the heap is empty!");
  }
    // ================================
    // throw the appropriate exception
    // ================================

  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return data.front();
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("the heap is empty!");
  }
    // ================================
    // throw the appropriate exception
    // ================================

  // only one element
  if(data.size() == 1) {

    // remove it
    data.pop_back();

    // return
    return;

  }
  
  // swap 1st and last
  data.front() = data.back();

  // then remove last
  data.pop_back(); 

  // bubble the new top down
 
 
  int index = 0;
  int n = data.size();

  while(true) {


    int best = index;
    

    // go through each child of the node
    for (int k = 1; k <= m; ++k) {

      int child_index = m * index + k;

      if(child_index < n && comp(data[child_index], data[best])) {

        best = child_index;

      }

    }
    // swap best child with current node
    if(best != index) {

      std::swap(data[index], data[best]);

      index = best;

    } 
    else {
      // no more better child
      break; 
    }

  }
  
}

// empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {

  return data.empty();
  
}

// size
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {

  return data.size();

}


#endif

