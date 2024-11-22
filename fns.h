#ifndef FNS_H
#define FNS_H
#include <vector>
#include <fstream>
#include <unordered_map>
#include "Person.h"


std::vector<std::string> splitString(const std::string& s, char splitter);
std::vector<std::string> readFile(std::ifstream &in);
void printData(std::ostream &out, const std::vector<std::string> &v);
Person getNameAndAmount(const std::string& information);
void createPeople(const std::vector<std::string> &information, std::vector<Person> &people);

#endif //FNS_H
