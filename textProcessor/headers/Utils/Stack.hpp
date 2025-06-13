/**
 * @file Stack.hpp
 * @author MK
 * @brief A simple stack implementation using a vector to store items.
 */
#pragma once
#include <vector>

using std::vector;

/**
 * @brief A simple stack implementation using a vector to store items.
 * 
 * This class provides basic stack operations such as push, pop, top, empty, and size.
 * It maintains a maximum size of 20 items, removing the oldest item when the limit is exceeded.
 */
template<typename T>
class Stack {
 public:
    Stack() = default;

    T top() {
      return itemList.back();
    }
    bool empty() {
      return itemList.size() == 0;
    }
    
    size_t size() {
      return itemList.size();
    }
    
    void push(const T item) {
      if(size() + 1 > 20)
      {
         itemList.erase(itemList.begin());
      }
      
      itemList.push_back(item);
    }
    void pop() {
       if(empty()) {
        return;
      }
      itemList.pop_back();
    }

 private:
    vector<T> itemList;
};