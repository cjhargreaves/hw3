#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

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
  ///
  std::vector<T> items_;
  int m_;
  PComparator comp_;

  size_t parent(size_t idx) const {
    return (idx - 1) / m_;
  }

  size_t kthChild(size_t idx, size_t k) const {
    return m_ * idx + k;
  }
  
  void heapifyUp(size_t idx);
  void heapifyDown(size_t idx);
  



};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c) {

  if (m < 2) {
    throw std::invalid_argument("m must be >= 2");
  }

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  items_.push_back(item);
  heapifyUp(items_.size() - 1);

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return items_.size();

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return items_.empty();
}



template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyUp(size_t idx) {

  // called after pushing a new element to maintain heap property
  // compares new element with parents and swaps if we need
  // continue until
  // 1. reach the root idx = 0
  // 2. the element is in correct position
  
  // loop until root
  while(idx > 0) {
    int p = parent(idx);
    
    // if the curr element is better than parent, we swap
    if(comp_(items_[idx], items_[p])) {

      std::swap(items_[idx], items_[p]);
      idx = p;

    }

    else {
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyDown(size_t idx) {

  // done after removing the root element
  // starts at root and moves an element down until heap restored
  // we need to compare all children up to m children

  size_t smallestChild;

  // loop while node has at least one child
  while(kthChild(idx, 1) < items_.size()) {
    smallestChild = kthChild(idx, 1);  
    
    for(int k = 2; k <= m_ && kthChild(idx, k) < items_.size(); k++) {
      int currentChild = kthChild(idx, k);

      if(comp_(items_[currentChild], items_[smallestChild])) {
        smallestChild = currentChild;
      }

    }
    
    if(comp_(items_[smallestChild], items_[idx])) {

      std::swap(items_[idx], items_[smallestChild]);
      idx = smallestChild;

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
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");



  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return items_[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }

  items_[0] = items_.back();
  items_.pop_back();

  if (!empty()) {
    heapifyDown(0);
  }



}



#endif

