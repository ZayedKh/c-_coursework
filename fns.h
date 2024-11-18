//
// Created by hp on 11/17/2024.
//

#ifndef FNS_H
#define FNS_H
#include <vector>
#include <fstream>
#include <unordered_map>

std::vector<std::string> readFile(std::ifstream &in);
void printData(std::ostream &out, const std::vector<std::string> &v);
std::string getName(std::string& s, std::unordered_map<std::string, std::vector<std::string>> &ms);
double getAmount(std::string& s, std::unordered_map<std::string, double> &md);

#endif //FNS_H
