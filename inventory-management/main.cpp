#include <iostream>
#include <cstdint>
#include <map>

class Product
{
private:
    uint32_t id;
    std::string name;

public:
    static uint32_t lastId;
    uint32_t getId()
    {
        return this->id;
    }

    std::string getName()
    {
        return this->name;
    }

    Product()
    {
        this->id = ++this->lastId;
    }

    ~Product()
    {

    }
};
uint32_t Product::lastId = 0;

int main()
{
    std::map<uint32_t, Product> products;
    Product *p1 { new Product() };
    Product *p2 { new Product() };

    std::cout << "p1 id: " << p1->getId() << '\n';
    std::cout << "p2 id: " << p2->getId() << '\n';
}
