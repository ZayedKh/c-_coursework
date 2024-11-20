//
// Created by hp on 11/17/2024.
//

#ifndef FNS_H
#define FNS_H
#include <vector>
#include <fstream>
#include <unordered_map>

std::vector<std::string> splitString(const std::string& s, char splitter);
std::vector<std::string> readFile(std::ifstream &in);
void populateMap(std::vector<std::string> &information, std::unordered_map<std::string, std::vector<std::string>> &itemMap, std::unordered_map<std::string, std::vector<double>> &amountMap);
void printData(std::ostream &out, const std::vector<std::string> &v);
void getNameAndAmount(const std::string& information, std::unordered_map<std::string,  std::vector<std::string>>& itemMap, std::unordered_map<std::string, std::vector<double>>& amountMap);
void printResults(std::ostream& out, const std::vector<std::string> &names, std::unordered_map<std::string, std::vector<std::string>> &itemMap, std::unordered_map<std::string, std::vector<double>> &amountMap);

#endif //FNS_H
