#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

vector<string> readFile(ifstream &in);

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

vector<string> readFile(ifstream &in)
{
    if(in.is_open() == 0)
    {
        throw domain_error("File is not open, unable to read");
    }

    string info;
    vector<string> details;

    while(getline(in, info))
    {
        details.push_back(info);
    }

    return details;
}
