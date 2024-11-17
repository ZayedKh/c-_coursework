//
// Created by hp on 11/17/2024.
//

#include "fns.h"
#include <iostream>
#include <fstream>
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
