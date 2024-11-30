#include "fns.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

std::vector<std::string> readPaymentsFile(std::ifstream& in)
{
    if (in.is_open() == 0) // Error case to handle invalid file.
    {
        throw std::domain_error("payments.txt is either not open, or empty. Unable to read.");
    }

    std::string info;
    std::vector<std::string> details;


    while (std::getline(in, info)) // While loop to push strings into vector<string>
    {
        details.push_back(info);

        if (splitString(info, ' ').size() != 3) // Error case to handle invalid file.
        {
            throw std::domain_error("Invalid file format, unable to read");
        }
    }

    if(details.empty()) // if vector is empty, throw error.
    {
        throw std::domain_error("payments.txt is empty, unable to read");
    }

    return details; // returns vector
}


std::vector<std::string> readPeopleFile(std::ifstream& in)
{
    if (in.is_open() == 0) // Error case to handle invalid file.
    {
        throw std::domain_error("people.txt is either not open, or empty. Unable to read.");
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

    const std::vector<std::string> segments = splitString(information, ' ');
    // calls split string method to split string into 3 segments - name, item, amount.

    try
    {
        const float amount = std::stof(segments[2]); // Convert string to float.
        Person people(segments[0], segments[1], amount); // Create person object with name, item, amount.

        return people; // return person object.
    }
    catch (const std::invalid_argument& e)
    {
        throw std::domain_error("Invalid argument, unable to convert string to float");
    }
}

void createPeople(const std::vector<std::string>& information, std::vector<Person>& people)
{
    for (auto& s : information) // For range loop to iterate over information vector.
    {
        people.push_back(getNameAndAmount(s));
        // Push back Person object returned by getNameAndAmount function into people vector.
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
                 std::unordered_map<std::string, std::vector<std::pair<std::string, float>>>& infoMap)
{
    for (const auto& p : people) // For range loop iterates over people vector
    {
        infoMap[p.getName()].emplace_back(std::make_pair(p.getItem(), p.getAmount()));
        // Emplace back to add item and amount to map.
    }
}


void printResults(std::ostream &out, const std::vector<std::string>& names,
                  std::unordered_map<std::string, std::vector<std::pair<std::string, float>>>& infoMap)
{
    if (names.empty()) // Throw error is names is empty.
    {
        throw std::domain_error("people.txt is empty, unable to print results");
    }

    for (const auto& name : names) // For range loop to iterate over names vector
    {
        out << name << "\n";
        float sum = 0; // Sum variable to store total amount

        for (const auto& p : infoMap[name]) // For range loop to iterate over infoMap pairs, based on name as key
        {
            out << p.first << ' ' << p.second << '\n'; // Prints item and amount
            sum += p.second;
        }

        out << "Total: " << sum << "\n\n";
    }
}
