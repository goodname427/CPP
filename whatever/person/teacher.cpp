#include <bits/stdc++.h>
#include "person.cpp"
using namespace std;

class Teacher : public Person
{
protected:
    string title;

public:
    Teacher(string name, int age, char sex, string address, string telephone, string title) : Person(name, age, sex, address, telephone), title(title)
    {
    }
    virtual void display()
    {
        Person::display();
        cout << title << endl;
    }
};