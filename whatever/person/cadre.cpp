#include <bits/stdc++.h>
#include "person.cpp"
using namespace std;

class Cadre : public Person
{
protected:
    string post;

public:
    Cadre(string name, int age, char sex, string address, string telephone, string post) : Person(name, age, sex, address, telephone), post(post)
    {
    }
    virtual void display()
    {
        Person::display();
        cout << post << endl;
    }
};
