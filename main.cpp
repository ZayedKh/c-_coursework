#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "fns.h"

using namespace std;


int main()
{

    ifstream in("E:/CppCW/Coursework/data/people.txt");
    ifstream pin("E:/CppCW/Coursework/data/payments.txt");

    vector<string> names = readFile(in);
    vector<string> information = readFile(pin);

    std::unordered_map<std::string, std::vector<std::string>> itemMap;
    std::unordered_map<std::string, std::vector<double>> amountMap;

    for(const auto& name : names)
    {
        itemMap[name];
        amountMap[name];
    }



    return 0;
}


