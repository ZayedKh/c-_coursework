#include "Person.h"

Person::Person (std::string name, std::string item, const float& amount) : name(std::move(name)), item(std::move(item)),
    amount(amount)
{
}
