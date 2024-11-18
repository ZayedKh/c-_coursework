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


    std::vector<std::string> vs;
    std::vector<double> vd;

    for (std::string& s : information)
    {
        getName(s, itemMap);
        getAmount(s, amountMap);
    }

    printResults(names, itemMap, amountMap);




    return 0;
}
