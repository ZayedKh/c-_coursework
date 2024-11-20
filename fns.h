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
void populateMap(std::vector<std::string> &vs, std::unordered_map<std::string, std::vector<std::string>> &ms);
void populateMap(std::vector<std::string> &vs, std::unordered_map<std::string, std::vector<double>> &md);
void printData(std::ostream &out, const std::vector<std::string> &v);
void getName(std::string& s, std::unordered_map<std::string, std::vector<std::string>> &ms);
void getAmount(std::string& s, std::unordered_map<std::string, std::vector<double>> &md);
void printResults(std::vector<std::string> &vs, std::unordered_map<std::string, std::vector<std::string>> &ms, std::unordered_map<std::string, std::vector<double>> &md);

#endif //FNS_H
