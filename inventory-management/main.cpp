#include <cstdio>
#include <iostream>
#include <unordered_map>

class Product
{
private:
    unsigned int id;
    unsigned int quantity;
    std::string name;

public:
    static unsigned int lastId;

    // setters
    const void setName(const std::string& name) { this->name = name; }
    // getters
    const unsigned int getId() const { return this->id; }
    const std::string& getName() const { return this->name; }

    // action methods
    const void update()
    {
        unsigned char answer{}; // y or n
        std::cout << "\nUpdating Product " << this->getId() << '\n';
        std::cout << "Want to update the name ("
            << this->getName() << ")? (y)es/(n)o: ";
        std::cin >> answer;

        if (answer == 'y') {
            std::cin >> this->name;
        }
        std::cout << "new name: " << this->getName() << " bilau\n";
    }

    Product(
        const std::string& name,
        const unsigned int quantity
    )
    {
        this->id = ++this->lastId;
        this->name = name;
        this->quantity = quantity;
    }

    ~Product()
    {
        std::cout << "deleting " << this->getId() << '\n';
    }
};
unsigned int Product::lastId = 0;

const void showMenu()
{
    std::cout << "\nSystem menu\n";
    std::cout << "1 - Insert product\n";
    std::cout << "2 - Update product\n";
    std::cout << "3 - Withdraw product\n";
    std::cout << "0 - Exit system\n";
}

const void listProducts(const std::unordered_map<unsigned int, Product*>* products)
{
    std::cout << "address of products: " << products << '\n';
    for (auto& product : *products) {
        std::cout << product.first
            << " - " << product.second->getName()
            << '\n';
    }
}

Product* insertProduct()
{
    std::string name{};
    unsigned int quantity{};

    std::cout << "Product name: ";
    std::cin >> name;

    std::cout << "Product quantity: ";
    std::cin >> quantity;

    return new Product(name, quantity);
}

int main()
{
    std::unordered_map<unsigned int, Product*> products{};
    std::cout << "address of products: " << &products << '\n';

    unsigned short choice{0};
    unsigned int selectedProductId;

    do {
        showMenu();
        std::cout << "Select an option: ";
        std::cin >> choice;
        std::cout << "\nYour choice: " << choice << '\n';

        switch(choice)
        {
            case 1:
                products[Product::lastId] = insertProduct();
                break;
            case 2:
                if (products.size() < 1)
                    break;

                listProducts(&products);
                std::cout << "Product ID to update: ";
                std::cin >> selectedProductId;
                products[selectedProductId]->update();
                break;
            case 3:
                if (products.size() < 1)
                    break;

                listProducts(&products);
                std::cout << "Product ID to remove: ";
                std::cin >> selectedProductId;
                if (products.find(selectedProductId) != products.end()) {
                    delete products[selectedProductId];
                    products.erase(selectedProductId);
                    std::cout << "\nProduct withdrawn\n";
                } else std::cout << "\nInvalid product\n";
                break;
            case 4:
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid option, try again." << '\n';
        }
    } while(choice != 0);

    for (auto& product : products) {
        delete product.second;
    }
}
