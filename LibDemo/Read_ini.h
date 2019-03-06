#pragma once
typedef std::map<std::string, std::map<std::string, std::string>> IniType;

void show_ini(IniType config);
IniType Read_ini(const char* filename);                         // 读取配置文件
vector<double> read_vector_from_ini(string line);

int GetIntFromKey(std::map<std::string, std::string> &strmap, std::string key);
double GetDoubleFromKey(std::map<std::string, std::string> &strmap, std::string key);
vector<double> GetVectorDoubleFromKey(std::map<std::string, std::string> &strmap, std::string key);
