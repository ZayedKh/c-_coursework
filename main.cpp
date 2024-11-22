#include <iostream>
#include "fns.h"
#include "Person.h"

int main()
{
    // Extracts file information into input streams in and pin
    std::ifstream in("data/people1.txt");
    std::ifstream pin("data/payments1.txt");

    // Puts file information into vectors
    std::vector<std::string> names = readPeopleFile(in);
    std::vector<std::string> information = readPaymentsFile(pin);

    // Vector of Person objects
    std::vector<Person> people;

    // HashMap to store person name, item, and amount
    std::unordered_map<std::string , std::vector<std::pair<std::string, double>>> infoMap;

    // Populate people vector with Person objects
    createPeople(information, people);

    // Populate infoMap with person name, item, and amount
    populateMap(people, infoMap);

    // Print results
    printResults(std::cout, names, infoMap);

    return 0;
}
