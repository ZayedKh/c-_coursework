#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "fns.h"


int main()
{
    std::ifstream in("data/people.txt");
    std::ifstream pin("data/payments.txt");

    std::vector<std::string> names = readFile(in);
    std::vector<std::string> information = readFile(pin);

    std::unordered_map<std::string, std::vector<std::string>> itemMap;
    std::unordered_map<std::string, std::vector<double>> amountMap;

    printData(std::cout, names);
    printData(std::cout, information);

    for (const auto& name : names)
    {
        itemMap[name];
        amountMap[name];
    }

    std::vector<std::string> vs;
    std::vector<double> vd;

    for (std::string& s : information)
    {
        vs.push_back(getName(s));
        // vd.push_back(getAmount(s));
    }


    for (int i = 0; i < vs.size(); ++i)
    {
        std::cout << "Item at index " << i << ": " << vs[i] << '\n';// "\nAmount at index " << i << ": " << vd[i] << '\n';
    }


    return 0;
}
