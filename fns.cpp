//
// Created by hp on 11/17/2024.
//

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
    if(v.empty()) // Error case to handle empty vector.
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

void getNameAndAmount(std::string& information, std::unordered_map<std::string,  std::vector<std::string>>& itemMap, std::unordered_map<std::string, std::vector<double>>& amountMap)
{

    if(information.size() == 0) // Error case to handle empty string.
    {
        throw std::domain_error("Empty string, unable to get name");
    }

    std::vector<std::string> segments = splitString(information, ' '); // calls split string method to split string into 3 segments - name, item, amount.
    double amount = std::stod(segments[2]);

    itemMap[segments[0]].push_back(segments[1]); // Push item into vector with name as key.
    amountMap[segments[0]].push_back(amount); // Push item into vector with name as key.
}


void printResults(std::ostream& out, std::vector<std::string>& names, std::unordered_map<std::string, std::vector<std::string>>& itemMap, std::unordered_map<std::string, std::vector<double>> &amountMap)
{
    for(int i = 0; i < names.size(); ++i) // Iterate over vector of string that contains the names from people.txt
    {
        out << names[i] << ": " << '\n';
        double total = 0; // total variable to sum the amounts
        for(int j = 0; j < itemMap[names[i]].size(); ++j) // For loop to iterate over each names item and amount
        {
            out <<  itemMap[names[i]][j] << " " << amountMap[names[i]][j] << '\n';
            total += amountMap[names[i]][j]; // Sum each amount to total
        }
        out << "Total: " << total << "\n\n"; // Print total
    }
}


void populateMap(std::vector<std::string>& information, std::unordered_map<std::string, std::vector<std::string>>& itemMap, std::unordered_map<std::string, std::vector<double>> &amountMap)
{
    for(auto& s : information) // For each loop to add each string to map
    {
        getNameAndAmount(s, itemMap,amountMap);
    }
}

std::vector<std::string> splitString(const std::string& s, char splitter)
{
    std::vector<std::string> segments;
    std::istringstream stream(s);
    std::string segment;

    while(std::getline(stream, segment, splitter))
    {
     segments.push_back(segment);
    }

    return segments;
}
