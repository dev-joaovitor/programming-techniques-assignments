#include <iostream>
#include <string>
#include "Product.h"

Product::Product(const std::string& name, const unsigned int& quantity)
    : name { name }
    , quantity { quantity }
{
    this->setId(++this->lastId);
}

const void Product::list()
{
    if (Product::products.empty()) {
        std::cout << "\n[NO PRODUCTS AVAILABLE]\n";
        return;
    }

    std::cout << "\n[AVAILABLE PRODUCTS]\n";
    for (auto& product : Product::products) {
        Product* p{ product.second };

        std::cout << "[" << p->getId() << "] - "
            << p->getName() << '\n';
    }
}

const void Product::createOne()
{
    std::string name{};
    unsigned int quantity{};

    std::cout << "\n[NEW PRODUCT]\n";
    std::cout << "Name: ";
    std::cin >> name;

    std::cout << "Quantity: ";
    std::cin >> quantity;

    Product::products[Product::lastId] = new Product(name, quantity);
}

const void Product::updateOne()
{
}

const void Product::deleteOne()
{
    if (Product::products.empty()) {
        std::cout << "\n[NO PRODUCTS AVAILABLE]\n";
        return;
    }
    Product::list();
    unsigned int productId{};
    std::cout << "\nEnter the id of the product which will be deleted: ";
    std::cin >> productId;

    if (Product::products.find(productId)
        == Product::products.end()) {
        std::cout << "\n[INVALID PRODUCT ID]\n";
        return;
    }
    delete Product::products[productId];
    Product::products.erase(productId);

    std::cout << "\n[PRODUCT " << productId
        << " SUCCESSFULLY DELETED]\n";
}

const void Product::deleteAll()
{
    for (auto& product : Product::products) {
        delete product.second;
    }
    Product::products.clear();
}

unsigned int Product::lastId{ 0 };
std::unordered_map<unsigned int, Product*> Product::products{};

