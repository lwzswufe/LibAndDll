#pragma once
enum class Gender {male, female, undef};
typedef std::map<std::string, std::map<std::string, std::string>> IniType;
extern IniType Read_ini(const char* filename);
extern void show_ini(IniType conf);

class Person
{
public:
    Person() :Person("unnamed", Gender::undef, NULL, NULL) {};
    ~Person();
    Person(string name, Gender gender) :Person(name, gender, NULL, NULL) {};
    Person(string name, Gender gender, Person* father, Person* mather);
    string name;
    vector<Person*> get_children();
    Person* get_father();
    Person* get_mother();
    Gender get_gender();
    void add_child(Person *p);
private:
    vector<Person*> children;
    Person* father;
    Person* mother;
    Gender gender;
};

Person * product_child(Person* father, Person* mother, string name, Gender gender);
void Show_Person(Person* p);


