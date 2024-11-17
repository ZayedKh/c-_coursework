#include <iostream>
#include <fstream>
#include <vector>
#include "fns.h"

using namespace std;


int main()
{

    ifstream in("E:/CppCW/Coursework/data/people.txt");
    ifstream pin("E:/CppCW/Coursework/data/payments.txt");

    vector<string> names = readFile(in);
    vector<string> information = readFile(pin);

    for(const auto& s : names)
    {
        cout << "Name: " << s << '\n';
    }

    for(const auto& s : information)
    {
        cout << "Details: " << s << '\n';
    }

    return 0;
}


