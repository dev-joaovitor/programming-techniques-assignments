#include <string>
#include <unordered_map>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
private:
    unsigned int id{};
    std::string username{};
    std::string password{};

    const void setId(const unsigned int& id) { this->id = id; };
    const std::string& getPassword() const { return this->password; };
public:
    static unsigned int lastId;
    static std::unordered_map<std::string, Employee*> employees;

    static const bool hasUnextractedInput();
    static const void ignoreLine();
    static const bool logIn();
    static const bool registerEmployee();
    static const void deleteAll();

    Employee(const std::string& username, const std::string& password);
};

#endif
