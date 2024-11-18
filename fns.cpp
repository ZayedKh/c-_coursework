//
// Created by hp on 11/17/2024.
//

#include "fns.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

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

void getName(std::string& s, std::unordered_map<std::string, std::vector<std::string>>& ms)
{

    if(s.size() == 0) // Error case to handle empty string.
    {
        throw std::domain_error("Empty string, unable to get name");
    }

    int index = 0; // Set index to zero, and initialize strings to ""
    std::string item = "", name = "";

    while (s[index] != ' ') // While loop to iterate over string until we come across a ' ' character
    {
        name += s[index]; // Add s[index] to name as it will always be the first word.
        ++index;
    }

    ++index; // Increment by one to ensure string starts with valid character rather than ' '


    while (s[index] != ' ') // While loop to extract item string from line.
    {
        item += s[index];
        ++index;
    }

    ms[name].push_back(item); // Push item into vector with name as key.
}

void getAmount(std::string& s, std::unordered_map<std::string, std::vector<double>>& md)
{

    if(s.empty())
    {
        throw std::domain_error("Empty string, unable to extract");
    }
    std::string amountString = "", name = ""; // Initialize strings to ""
    double amount;
    int count = 0, index = 0;

    /*
     * While loop to occur while count is not equal to 2, everytime we come across aa ' ' character we increase count by one.
     * Count will never be greater than 2 as there are 2 spaces in the string e.g. "Bob eggs 1.5"
     * If count is = 0, we know the string will be the name
     * Once count is > 0, we know that we have extracted the full name
     * */
    while(count != 2)
    {
        if (s[index] == ' ')
        {
            ++count;
        }

        if(count < 1)
        {
            name += s[index];
        }

        ++index;
    }

    // Once count = 2, we know that the next values will be the amount

    while(index < s.size()) // While loop to extract amount
    {
        amountString += s[index];
        ++index;
    }

    amount = std::stod(amountString); // stod to covert string to double
    md[name].push_back(amount); // Push amount into map with name as key.
}

void printResults(std::vector<std::string>& vs, std::unordered_map<std::string, std::vector<std::string>>& ms, std::unordered_map<std::string, std::vector<double>> &md)
{
    for(int i = 0; i < vs.size(); ++i) // Iterate over vector of string that contains the names from people.txt
    {
        std::cout << vs[i] << ": " << '\n';
        double total = 0; // total variable to sum the amounts
        for(int j = 0; j < ms[vs[i]].size(); ++j) // For loop to iterate over each names item and amount
        {
            std::cout <<  ms[vs[i]][j] << " " << md[vs[i]][j] << '\n';
            total += md[vs[i]][j]; // Sum each amount to total
        }
        std::cout << "Total: " << total << "\n\n"; // Print total
    }
}

void populateMap(std::vector<std::string>& vs, std::unordered_map<std::string, std::vector<double>>& md)
{
    for (auto& s : vs) // For each loop to add each string to map
    {
        getAmount(s,md);
    }
}

// Overloaded method
void populateMap(std::vector<std::string>& vs, std::unordered_map<std::string, std::vector<std::string>>& ms)
{
    for(auto& s : vs) // For each loop to add each string to map
    {
        getName(s, ms);
    }
}

