#include <iostream>
#include <string>
#include "Product.h"

Product::Product(const std::string& name, const unsigned int& quantity)
    : name { name }
    , quantity { quantity }
{
    this->setId(++this->lastId);
}

const void Product::list(const std::unordered_map<unsigned int, Product*>& products)
{
    if (products.size() < 1) {
        std::cout << "\n[NO PRODUCTS AVAILABLE]\n";
        return;
    }

    std::cout << "\n[AVAILABLE PRODUCTS]\n";
    for (auto& product : products) {
        Product* p{ product.second };

        std::cout << "[" << p->getId() << "] - "
            << p->getName() << '\n';
    }
}

Product* Product::create()
{
    std::string name{};
    unsigned int quantity{};

    std::cout << "\n[NEW PRODUCT]\n";
    std::cout << "Name: ";
    std::cin >> name;

    std::cout << "Quantity: ";
    std::cin >> quantity;

    return new Product(name, quantity);
}

unsigned int Product::lastId{ 0 };
