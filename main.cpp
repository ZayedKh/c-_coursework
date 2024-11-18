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

    std::vector<std::string> vs;
    std::vector<double> vd;

    for (std::string& s : information)
    {
        getName(s, itemMap);
        getAmount(s, amountMap);
    }


    for(int i = 0; i < names.size(); ++i)
    {
        std::cout << names[i] << ": " << '\n';
        double total = 0;
        for(int j = 0; j < itemMap[names[i]].size(); ++j)
        {
            std::cout <<  itemMap[names[i]][j] << " " << amountMap[names[i]][j] << '\n';
            total += amountMap[names[i]][j];
        }
        std::cout << "Total: " << total << "\n\n";
    }

    return 0;
}
