#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "fns.h"


int main()
{
    // Extracts file information into input streams in and pin
    std::ifstream in("data/people.txt");
    std::ifstream pin("data/payments.txt");

    // Puts file information into vectors
    std::vector<std::string> names = readFile(in);
    std::vector<std::string> information = readFile(pin);

    // Create HashMaps to store name as key, with item/amount bought as value
    std::unordered_map<std::string, std::vector<std::string>> itemMap;
    std::unordered_map<std::string, std::vector<double>> amountMap;

    // Functions in fns.cpp and fns.h to populate the hashmaps with relevant information from vector<string>
    populateMap(information, itemMap);
    populateMap(information, amountMap);

    // Function to print the results in the required format
    printResults(names, itemMap, amountMap);

    return 0;
}
