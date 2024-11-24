#ifndef FNS_H
#define FNS_H
#include <vector>
#include <fstream>
#include <unordered_map>
#include "Person.h"



std::vector<std::string> splitString(const std::string& s, char splitter);
std::vector<std::string> readPeopleFile(std::ifstream& in);
std::vector<std::string> readPaymentsFile(std::ifstream& in);
void printData(std::ostream &out, const std::vector<std::string> &v);
Person getNameAndAmount(const std::string& information);
void createPeople(const std::vector<std::string> &information, std::vector<Person> &people);
void populateMap(const std::vector<Person> &people, std::unordered_map<std::string , std::vector<std::pair<std::string, float>>> &infoMap);
void printResults(std::ostream& out, const std::vector<std::string> &names, std::unordered_map<std::string , std::vector<std::pair<std::string, float>>> &infoMap);

#endif //FNS_H
