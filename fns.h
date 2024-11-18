//
// Created by hp on 11/17/2024.
//

#ifndef FNS_H
#define FNS_H
#include <vector>
#include <fstream>

std::vector<std::string> readFile(std::ifstream &in);
void printData(std::ostream &out, const std::vector<std::string> &v);
std::string getName(std::string &s);
double getAmount(std::string &s);

#endif //FNS_H
