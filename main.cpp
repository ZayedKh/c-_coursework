#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "fns.h"
#include "Person.h"

int main()
{
    // Extracts file information into input streams in and pin
    std::ifstream in("data/people.txt");
    std::ifstream pin("data/payments.txt");

    // Puts file information into vectors
    std::vector<std::string> names = readFile(in);
    std::vector<std::string> information = readFile(pin);

    // Vector of Person objects
    std::vector<Person> people;

    // HashMap to store person name, item, and amount
    std::unordered_map<std::string , std::pair<std::string, double>>;

    // Populate people vector with Person objects
    createPeople(information, people);

    for(const auto &p : people)
    {
        std::cout << p.getName() << " " << p.getItem() << " " << p.getAmount() << '\n';
    }




    return 0;
}
