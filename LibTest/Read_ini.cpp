#include "pch.h"
#include "Read_ini.h"

void ini_file_line_parse(char* line, std::string &key, std::string &value)
{   // 拆分一行字符串  
    char * pch_1;
    char * pch_2;
    char * next_token = NULL;
    pch_1 = strtok_s(line, "=[]\n", &next_token);
    if (pch_1 != NULL)
        key = pch_1;
    else
        key = "";

    pch_2 = strtok_s(NULL, "=[]\n", &next_token);
    if (pch_2 != NULL)
        value = pch_2;
    else
        value = "";
}


IniType Read_ini(const char* filename)
{   // 读取配置文件
    const size_t line_size{ 1024 };
    char line[line_size];
    std::string key, value, temp_key{""};

    std::map<std::string, std::map<std::string, std::string>> config;
    std::ifstream input;

    input.open(filename);
    if (input.fail() || input.bad())
    {   
        char s[line_size];
        sprintf_s(s, "%s Line %d error in read %s\n", __func__, __LINE__, filename);
        printf(s);
        throw runtime_error(s);
    }
    while(!input.eof())
    {
        input.getline(line, line_size);
        ini_file_line_parse(line, key, value);
        if (key == "")
        {
            continue;
        }
        if (value == "")
        {   
            std::map<std::string, std::string> temp_map;
            config[key] = temp_map;
            temp_key = key;
        }
        else
        {
            config[temp_key][key] = value;
        }
    }
    input.close();
    return config;
}

void show_ini(IniType config)
{   //显示配置文件的内容
    char buffer[100];
    for (auto i= config.begin(); i!= config.end(); i++)
    {   
        std::string key = i->first;
        auto value      = i->second;
        sprintf_s(buffer, "[%s]:\n", key.data());
        fputs (buffer , stdout);  
        for (auto ii= value.begin(); ii != value.end(); ii++)
        {
            std::string key_   = ii->first;
            std::string value_ = ii->second;
            sprintf_s(buffer, "        <%s : %s>\n", key_.data(), value_.data());
            fputs (buffer , stdout);  
        }
    }
}

vector<double> read_vector_from_ini(string linestr)
{   
    vector<double> vec_d;
    char *word, *next_token = NULL, line_c[1024];
    strncpy_s(line_c, linestr.c_str(), 1024);
    word = strtok_s(line_c, ",=[]\n", &next_token);
    while (word != NULL)
    {   
        vec_d.push_back(atof(word));
        word = strtok_s(NULL, ",=[]\n", &next_token);
    }
    return vec_d;
}

int GetIntFromKey(std::map<std::string, std::string> &strmap, std::string key)
{
    string value = strmap[key];
    char s[128];
    int i;
    if (value.empty())
    {
        sprintf_s(s, "No Key Named %s\n", value.c_str());
        printf(s);
        i = 0;
    }
    else
    {   
        i = stoi(value);
        printf("Set %s:%d\n", key.c_str(), i);
    }
    return i;
}

double GetDoubleFromKey(std::map<std::string, std::string> &strmap, std::string key)
{
    string value = strmap[key];
    char s[128];
    double d;
    if (value.empty())
    {
        sprintf_s(s, "No Key Named %s\n", value.c_str());
        printf(s);
        d = 0;
    }
    else
    {
        d = stoi(value);
        printf("Set %s:%.4lf\n", key.c_str(), d);
    }
    return d;
}

vector<double> GetVectorDoubleFromKey(std::map<std::string, std::string> &strmap, std::string key)
{
    string value = strmap[key];
    char s[128];
    vector<double> vec_d;
    if (value.empty())
    {
        sprintf_s(s, "No Key Named %s\n", value.c_str());
        printf(s);
    }
    else
    {
        vec_d = read_vector_from_ini(value);
        printf("Set %s:", key.c_str());
        for (double d : vec_d)
        {
            printf("%.4lf, ", d);
        }
        printf("\n");
    }
    return vec_d;
}
