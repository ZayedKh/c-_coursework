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
    double amount = std::stod(segments[2]);

    Person people(segments[0], segments[1], amount); // Create person object with name, item, amount.

    return people; // return person object.
}

void createPeople(const std::vector<std::string> &information, std::vector<Person> &people)
{
    for (auto &s : information)
    {
        people.push_back(getNameAndAmount(s));
    }
}

std::vector<std::string> splitString(const std::string& s, char splitter)
{
    std::vector<std::string> segments;
    std::istringstream stream(s);
    std::string segment;

    while (std::getline(stream, segment, splitter))
    {
        segments.push_back(segment);
    }

    return segments;
}
