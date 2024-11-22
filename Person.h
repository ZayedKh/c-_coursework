#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
    std::string name;
    std::string item;
    double amount;

public:
    Person(const std::string& name, const std::string& item, const double& amount);
    const std::string getName() const { return name; }
    const std::string getItem() const { return item; }
    const double getAmount() const { return amount; }
};

#endif //PERSON_H
