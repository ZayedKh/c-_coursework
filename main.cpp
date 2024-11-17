#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "fns.h"



int main()
{
    std::ifstream in("E:/CppCW/Coursework/data/people.txt");
    std::ifstream pin("E:/CppCW/Coursework/data/payments.txt");

    std::vector<std::string> names = readFile(in);
    std::vector<std::string> information = readFile(pin);

    printData(std::cout, names);
    printData(std::cout, information);

    

    return 0;
}


