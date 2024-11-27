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
    void setName(const std::string& name)
    {
        this->name = name;
    }
    // getters
    const unsigned int getId()
    {
        return this->id;
    }

    const std::string& getName()
    {
        return this->name;
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

void listProducts(const std::unordered_map<unsigned int, Product*>* products)
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
                listProducts(&products);
                break;
            case 3:
                listProducts(&products);
                unsigned int productId;
                std::cout << "Product ID to remove: ";
                std::cin >> productId;
                if (products.find(productId) != products.end()) {
                    products.erase(productId);
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
