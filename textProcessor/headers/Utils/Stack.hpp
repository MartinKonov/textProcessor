#pragma once
#include <vector>

using std::vector;


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