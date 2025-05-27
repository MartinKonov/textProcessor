#pragma once
#include "../FileManager.hpp"
#include <stdexcept>

template <typename Derived, typename T, typename ParserType>
class DataRegister {
 public:

    vector<T*> getAll() const {
        return items;
    }


    T* getItem(const string& name) const {
        if (name.empty()) {
            throw std::runtime_error(Derived::getType() + "::getItem: name is empty");
        }
        int index = findIndex(name);
        if (index == -1) {
            throw std::runtime_error(Derived::getType() + "::getItem: \"" + name + "\" not found");
        }
        return items[index];
    }

    void removeItem(const string& name) {
        if (name.empty()) {
            throw std::runtime_error(Derived::getType() + "::removeItem: name is empty");
        }
        int index = findIndex(name);
        if (index == -1) {
            return;
        }

        T* toDelete = items[index];
        items.erase(items.begin() + index);
        delete toDelete;

        try {
            parser->save(items);
        } catch (const std::runtime_error& e) {
            throw std::runtime_error(Derived::getType() + "::removeItem: " + e.what());
        }
    }

    string showAll() const {
        string out;
        for (T* item : items) {
            out += parser->serialize(item);
        }
        return out;
    }

 protected:

    ParserType* parser;
    vector<T*> items;

    DataRegister() {
        parser = ParserType::getInstance();
        try {
            items = parser->load();
        } catch (const std::runtime_error& e) {
            throw std::runtime_error(Derived::getType() + "::ctor: " + e.what());
        }
    }

    ~DataRegister() {
        for (T* item : items) {
            delete item;
        }
        items.clear();
    }

    int findIndex(const string& name) const {
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i]->getName() == name) {
                return i;
            }
        }
        return -1;
    }

    void addItem(T* newItem) {
        const string name = Derived::getItemName(newItem);
        if (name.empty()) {;
            throw std::runtime_error(Derived::getType() + "::addItem: name is empty");
        }
        if (findIndex(name) != -1) {
            throw std::logic_error(Derived::getType() + "::addItem: item with name \"" + name + "\" already exists");
        }

        items.push_back(newItem);
        try {
            parser->save(newItem);
        } catch (const std::runtime_error& e) {
            throw std::runtime_error(Derived::getType() + "::addItem: " + e.what());
        }
    }
};