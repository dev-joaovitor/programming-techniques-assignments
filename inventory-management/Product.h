#include <iostream>
#include <unordered_map>
#include <string>

#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
private:
    unsigned int id{};
    std::string name{};
    unsigned int quantity{};

public:
    // static members
    static unsigned int lastId;

    // getters
    const unsigned int getId() const { return this->id; }
    const std::string getName() const { return this->name; }
    const unsigned int getQuantity() const { return this->quantity; }

    // setters
    const void setId(const unsigned int& id) { this->id = id; };
    const void setName(const std::string& name) { this->name = name; };
    const void setQuantity(const unsigned int& quantity) { this->quantity = quantity; };

    // static members function
    static const void list(const std::unordered_map<unsigned int, Product*>& products);
    static Product* create();

    // constructor
    Product(const std::string& name, const unsigned int& quantity);
};

#endif
