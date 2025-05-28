#pragma once
#include <vector>

using std::vector;


template<typename T>
class Stack {
 public:
    Stack() = default;

    T* top();
    bool empty();
    size_t size();
    void push(T item);
    void pop();

 private:
    vector<T*> itemList;
};