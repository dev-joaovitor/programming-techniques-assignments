#include <iostream>
#include "Product.h"

const void handleOptions(unsigned short& option)
{
    std::cout << "\n[OPTIONS]\n";
    std::cout << "\n1 - Insert product";
    std::cout << "\n2 - Update product";
    std::cout << "\n3 - Use product";
    std::cout << "\n4 - Restock product";
    std::cout << "\n5 - Remove product";
    std::cout << "\n6 - List products";
    std::cout << "\n0 - EXIT";
    std::cout << "\nSelect an option: ";
    std::cin >> option;
}

int main()
{
    unsigned short option{};

    do {
        handleOptions(option);
        switch(option)
        {
            case 1:
                Product::createOne();
                break;
            case 2:
                Product::updateOne();
                break;
            case 3:
                Product::use();
                break;
            case 4:
                Product::restock();
                break;
            case 5:
                Product::deleteOne();
                break;
            case 6:
                Product::list(true);
                break;
            case 0: break;
            default:
                std::cout << "\n[INVALID OPTION]\n";
        }
    } while(option != 0);

    Product::deleteAll();

    return 0;
}
