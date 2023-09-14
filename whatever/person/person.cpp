#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    char sex;
    string address;
    string telephone;

public:
    Person(string name, int age, char sex, string address, string telephone) : name(name),
                                                                               age(age),
                                                                               sex(sex),
                                                                               address(address),
                                                                               telephone(telephone)
    {
    }
    virtual void display()
    {
        cout << name << endl
             << age << endl
             << sex << endl
             << address << endl
             << telephone << endl;
    }
};
