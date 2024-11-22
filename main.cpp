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
    std::unordered_map<std::string , std::vector<std::pair<std::string, double>>> infoMap;

    // Populate people vector with Person objects
    createPeople(information, people);

    // Populate infoMap with person name, item, and amount
    populateMap(people, infoMap);

    // Print results
    printResults(names, infoMap);

    return 0;
}
