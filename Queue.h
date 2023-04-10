#pragma once
#include <cstddef>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
  T* data;
  size_t front;
  size_t back;
  size_t capacity;
  size_t num_items;


  // Default size of the underlying array.
  static const size_t DEFAULT_SIZE = 50;
  // Size to increment the underlying array by.
  static const size_t INCREMENT_SIZE = 50;
  
  // Private function to increase the size of the underlying array.
  void resize() {
    // Calculate the new capacity and create a new data array of that size.
    size_t new_capacity = capacity + INCREMENT_SIZE;
    T* new_data = new T[new_capacity];

    size_t old_index = front;
    // Start at the front and wrap around the array.
    for (size_t new_index = 0; new_index < capacity; new_index++) {
      new_data[new_index] = data[old_index];
      old_index = ((old_index + 1) % capacity);
    }

    // Delete old data and reassign to new.
    delete[] data;
    data = new_data;

    // Assign the new values.
    front = 0;
    back = capacity;
    capacity = new_capacity;
  }
  
public:
  // Constructor
  Queue(size_t size = DEFAULT_SIZE) {
    // Set the capacity
    capacity = size;
    data = new T[capacity];
    front = 0;
    back = 0;
    num_items = 0;
  }

  // Destructor
  ~Queue() {
    // All that this needs is to delete the dynamic array.
    delete[] data;
  }

  // Push an object to the back of the Queue.
  void push(T item) {
    // If this operation will overfill the underlying array, resize it.
    if (num_items == capacity) {
      resize();
    }

    // Assign the item at the new back index.
    data[back] = item;

    // Increment the back index. If the index will fall off the end of
    // the array, wrap around to the front.
    back = ((back + 1) % capacity);

    // Increase the number of items.
    num_items++;
  }

  // Remove the element at the front of the queue and return it.
  T pop() {
    // Raise an out_of_bounds error if popping from an empty Queue.
    if (num_items == 0) {
      throw out_of_range("Cannot pop from an empty Queue");
    }
    
    // Save the item at the front.
    T popped_item = data[front];
    // Increment the front index. If the index will fall off the end of
    // the array, wrap around to the front.
    front = ((front + 1) % capacity);

    // Decrease the number of items.
    num_items--;
    
    // Return the popped item.
    return popped_item;
  }

  // Return the front element of the Queue.
  T top() const {
    return data[front];
  }

  // Return the size of the Queue.
  size_t size() const {
    return num_items;
  }

  // Returns if the queue is empty.
  bool empty() const {
    return (num_items == 0);
  }
};
