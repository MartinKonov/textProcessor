#include "../../headers/Utils/Stack.hpp"


template<typename T>
T* Stack<T>::top() {
    return itemList.back();
}

template<typename T>
bool Stack<T>::empty() {
    return itemList.size() == 0;
}

template<typename T>
size_t Stack<T>::size() {
    return itemList.size();
}

template<typename T>
void Stack<T>::push(T item) {
    itemList.push_back(item);
}

template<typename T>
void Stack<T>::pop() {
    if(empty()) {
        return;
    }
    itemList.pop_back();
}