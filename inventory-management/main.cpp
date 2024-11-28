#include <iostream>
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
    unsigned short choice{};

    do {
        showMenuOptions();
        std::cin >> choice;
        switch(choice)
        {
            case 1:
                Product::create();
                break;
            case 2:
                Product::list();
                break;
            case 3:
                Product::list();
                break;
            case 4:
                break;
        }
    } while(choice != 0);

    Product::deleteAll();

    return 0;
}
