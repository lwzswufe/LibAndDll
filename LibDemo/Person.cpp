#include "stdafx.h"
#include "Person.h"

Person::Person(string name, Gender gender, Person* father, Person* mather)
{
    this->gender = gender;
    this->name = name;
    this->father = father;
    this->mother = mather;
    IniType conf = Read_ini("Trade.ini");
    show_ini(conf);
}

Person::~Person()
{
}

vector<Person*> Person::get_children()
{
    return this->children;
}

Person* Person::get_father()
{
    return this->father;
}

Person* Person::get_mother()
{
    return this->mother;
}

Gender Person::get_gender()
{
    return this->gender;
}

void Person::add_child(Person *p)
{
    this->children.push_back(p);
}

Person * product_child(Person* father, Person* mother, string name, Gender gender)
{
    if (father == NULL || mother == NULL)
    {
        return NULL;
    }
    Person *person_ptr = new Person{ name, gender, father, mother };
    father->add_child(person_ptr);
    mother->add_child(person_ptr);
    return person_ptr;
}

void Show_Person(Person* p)
{
    if (p == NULL)
        cout << "Person:NULL" << endl;
    cout << "Name:" << p->name << endl;

    cout << "Father:";
    if (p->get_father() == NULL)
        cout << "NULL" << endl;
    else
        cout << p->get_father()->name << endl;

    cout << "Mother:";
    if (p->get_mother() == NULL)
        cout << "NULL" << endl;
    else
        cout << p->get_mother()->name << endl;

    vector<Person*> children = p->get_children();
    cout << "Children:";
    if (children.empty())
        cout << "NULL";
    for (auto child : children)
        cout << child->name << ", ";
    cout << endl;

}