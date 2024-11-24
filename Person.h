#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
    const std::string name;
    const std::string item;
    const float amount;

public:
    Person(std::string name, std::string item, const float& amount);
    const std::string& getName() const { return name; }
    const std::string& getItem() const { return item; }
    const float& getAmount() const { return amount; }
};

#endif //PERSON_H
