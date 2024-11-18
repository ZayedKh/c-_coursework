//
// Created by hp on 11/17/2024.
//

#include "fns.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

std::vector<std::string> readFile(std::ifstream &in)
{
    if(in.is_open() == 0)
    {
        throw std::domain_error("File is not open, unable to read");
    }

    std::string info;
    std::vector<std::string> details;

    while(std::getline(in, info))
    {
        details.push_back(info);
    }

    return details;
}

void printData(std::ostream& out, const std::vector<std::string>& v)
{
    out << "Vector:\n";

    for(const auto& s : v)
    {
        out << s << '\n';
    }

    out << '\n';
}

std::string getName(std::string& s, std::unordered_map<std::string, std::vector<std::string>> &ms)
{
    int index = 0;

    while (s[index] != ' ')
    {
        ++index;
    }

    ++index;

    std::string item = "";

    while(s[index] != ' ')
    {
        item += s[index];
        ++index;
    }

    return item;
}

double getAmount(std::string& s, std::unordered_map<std::string, double> &md)
{
    const auto n = s.size();
    std::string amountString = "";
    double amount;

    int index = n - 2;

    while(s[index] != ' ')
    {
        amountString += s[index];
        --index;
    }

    amount = std::stod(amountString);

    return amount;
}