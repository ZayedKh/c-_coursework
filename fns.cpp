#include "fns.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> readFile(std::ifstream& in)
{
    if (in.is_open() == 0) // Error case to handle invalid file.
    {
        throw std::domain_error("File is not open, unable to read");
    }

    std::string info;
    std::vector<std::string> details;

    while (std::getline(in, info)) // While loop to push strings into vector<string>
    {
        details.push_back(info);
    }

    return details; // returns vector
}

void printData(std::ostream& out, const std::vector<std::string>& v)
{
    if (v.empty()) // Error case to handle empty vector.
    {
        throw std::domain_error("Vector is empty, unable to print data");
    }
    out << "Vector:\n";

    for (const auto& s : v) // For-each loop to iterate over vector and print string.
    {
        out << s << '\n';
    }

    out << '\n';
}

Person getNameAndAmount(const std::string& information)
{
    if (information.empty()) // Error case to handle empty string.
    {
        throw std::domain_error("Empty string, unable to get name");
    }


    std::vector<std::string> segments = splitString(information, ' ');
    // calls split string method to split string into 3 segments - name, item, amount.
    const double amount = std::stod(segments[2]); // Convert string to double.

    Person people(segments[0], segments[1], amount); // Create person object with name, item, amount.

    return people; // return person object.
}

void createPeople(const std::vector<std::string>& information, std::vector<Person>& people)
{
    for (auto& s : information) // For range loop to iterate over information vector.
    {
        people.push_back(getNameAndAmount(s)); // Push back Person object returned by getNameAndAmount function into people vector.
    }
}

std::vector<std::string> splitString(const std::string& s, char splitter)
{
    std::vector<std::string> segments; // Vector to store segments of string.
    std::istringstream stream(s); // String stream to read string.
    std::string segment; // String to store segment.

    while (std::getline(stream, segment, splitter)) // While loop to split string into segments.
    {
        segments.push_back(segment); // Push segment into vector.
    }

    return segments;
}

void populateMap(const std::vector<Person>& people,
                 std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& infoMap)
{
    for (const auto& p : people) // For range loop iterates over people vector
    {
        infoMap[p.getName()].emplace_back(std::make_pair(p.getItem(), p.getAmount())); // Emplace back to add item and amount to map.
    }
}


void printResults(const std::vector<std::string>& names,
                  std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& infoMap)
{
    if (names.empty()) // Throw error is names is empty.
    {
        throw std::domain_error("people.txt is empty, unable to print results");
    }

    for (const auto& name : names) // For range loop to iterate over names vector
    {
        std::cout << name << ":\n";
        double sum = 0; // Sum variable to store total amount

        for (const auto& p : infoMap[name]) // For range loop to iterate over infoMap pairs, based on name as key
        {
            std::cout << p.first << ' ' << p.second << '\n'; // Prints item and amount
            sum += p.second;
        }

        std::cout << "Total: " << sum << "\n\n";
    }
}
