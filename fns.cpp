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
    if (in.is_open() == 0)
    {
        throw std::domain_error("File is not open, unable to read");
    }

    std::string info;
    std::vector<std::string> details;

    while (std::getline(in, info))
    {
        details.push_back(info);
    }

    return details;
}

void printData(std::ostream& out, const std::vector<std::string>& v)
{
    out << "Vector:\n";

    for (const auto& s : v)
    {
        out << s << '\n';
    }

    out << '\n';
}

void getName(std::string& s, std::unordered_map<std::string, std::vector<std::string>>& ms)
{
    int index = 0;
    std::string item = "", name = "";

    while (s[index] != ' ')
    {
        name += s[index];
        ++index;
    }

    ++index;


    while (s[index] != ' ')
    {
        item += s[index];
        ++index;
    }

    ms[name].push_back(item);
}

void getAmount(std::string& s, std::unordered_map<std::string, std::vector<double>>& md)
{
    const auto n = s.size();
    std::string amountString = "", name = "";
    double amount;
    int count = 0, index = 0;

    while(count != 2)
    {
        //Bob egg 1.5
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

    while(index < s.size())
    {
        amountString += s[index];
        ++index;
    }

    amount = std::stod(amountString);
    md[name].push_back(amount);

}
