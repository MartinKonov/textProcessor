/**
 * @file DataRegister.hpp
 * @brief A template class for managing a collection of items with a specific data type.
 * This class provides methods to add, retrieve, remove, and display items, as well as to parse and serialize them using a specified parser type.
 */
#pragma once
#include "../FileManager.hpp"
#include <stdexcept>

using std::logic_error;
using std::runtime_error;

/**
 * @class DataRegister
 * @brief A template class for managing a collection of items with a specific data type.
 */
template <typename Derived, typename T, typename ParserType>
class DataRegister {
 public:

    /**
     * @brief Returns all items in the register.
     * @return A vector of pointers to all items.
     */
    vector<T*> getAll() const {
        return items;
    }

    /**
     * @brief Returns an item by its name from the register.
     * @param name The name of the item to retrieve.
     * @return A pointer to the item if found.
     * @throws std::runtime_error if the name is empty or the item is not found.
     */
    T* getItem(const string& name) const {
        if (name.empty()) {
            throw runtime_error("Get Item: name is empty");
        }
        int index = findIndex(name);
        if (index == -1) {
            throw runtime_error("Get Item: \"" + name + "\" not found");
        }
        return items[index];
    }

    bool itemExists(const string& name) const {
        return findIndex(name) != -1;
    }

    /**
     * @brief Removes an item by its name from the register.
     * @param name The name of the item to remove.
     * @throws std::runtime_error if the name is empty or there is an error during file operations.
     */
    void removeItem(const string& name) {
        if (name.empty()) {
            throw runtime_error(ERROR_INVALID_ITEM_NAME);
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
        } catch (const runtime_error& e) {
            throw runtime_error(string(e.what()));
        }
    }

    /**
     * @brief Shows all items in the register as a concatenated string.
     * @return A string containing the serialized representation of all items.
     */
    string showAll() const {
        string out;
        for (T* item : items) {
            out += parser->serialize(item);
        }
        return out;
    }

    /**
     * @brief Finds the index of an item by its name.
     * @param name The name of the item to find.
     * @return The index of the item if found, otherwise -1.
     */
    int findIndex(const string& name) const {
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i]->getName() == name) {
                return i;
            }
        }
        return -1;
    }


 protected:

    ParserType* parser;
    vector<T*> items;

    /**
     * @brief Constructor for DataRegister.
     * Initializes the parser and loads items from the data file.
     * @throws std::runtime_error if there is an error during file operations.
     */
    DataRegister() {
        parser = ParserType::getInstance();
        try {
            items = parser->load();
        } catch (const runtime_error& e) {
            throw runtime_error(e.what());
        }
    }

    /**
     * @brief Destructor for DataRegister.
     * Cleans up the items in the register.
     */
    ~DataRegister() {
        for (T* item : items) {
            delete item;
        }
        items.clear();
        parser->destroyInstance();
    }

    /**
     * @brief Adds a new item to the register.
     * @param newItem A pointer to the item to be added.
     * @throws std::runtime_error if the name is empty or an item with the same name already exists.
     * @details This method adds a new item to the register and saves it using the parser.
     */
    void addItem(T* newItem) {
        const string name = Derived::getItemName(newItem);
        if (name.empty()) {;
            throw runtime_error(ERROR_INVALID_ITEM_NAME);
        }
        if (findIndex(name) != -1) {
            throw logic_error("Item with name \"" + name + "\" already exists");
        }

        items.push_back(newItem);
        try {
            parser->save(newItem);
        } catch (const std::runtime_error& e) {
            throw runtime_error(e.what());
        }
    }
};