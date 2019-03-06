#pragma once
#include <map>
#include <string>
using std::string;

#include <cstdio>

#include <iostream>
using std::cout; using std::endl; using std::ostream;
#include <vector>
using std::vector;
#include <cmath>
#include <exception>
using std::runtime_error;
using std::logic_error;
using std::range_error;

#include <sstream>
using std::istringstream;
using std::ostringstream;

#include <fstream>
using std::ifstream;
using std::ofstream;
typedef std::map<std::string, std::map<std::string, std::string>> IniType;

void show_ini(IniType config);
IniType Read_ini(const char* filename);                         // 读取配置文件
vector<double> read_vector_from_ini(string line);

int GetIntFromKey(std::map<std::string, std::string> &strmap, std::string key);
double GetDoubleFromKey(std::map<std::string, std::string> &strmap, std::string key);
vector<double> GetVectorDoubleFromKey(std::map<std::string, std::string> &strmap, std::string key);
