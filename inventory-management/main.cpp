#include <iostream>
#include <unordered_map>
#include "Product.h"

const void showMenuOptions()
{
    std::cout << "\n[OPTIONS]\n";
    std::cout << "\n1 - Insert product";
    std::cout << "\n2 - Update product";
    std::cout << "\n3 - Use product";
    std::cout << "\n4 - Remove product";
    std::cout << "\nSelect an option: ";
}

int main()
{
    std::unordered_map<unsigned int, Product*> products{};

    unsigned short choice{};

    do {
        showMenuOptions();
        std::cin >> choice;
        switch(choice)
        {
            case 1:
                products[Product::lastId] = Product::create();
                break;
            case 2:
                Product::list(products);
                break;
            case 3:
                Product::list(products);
                break;
            case 4:
                break;
        }
    } while(choice != 0);

    for (auto& product : products) {
        delete product.second;
    }
    return 0;
}
