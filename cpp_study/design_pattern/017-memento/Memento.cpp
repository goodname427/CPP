#include <string>
#include <iostream>
using namespace std;

class Memento
{
private:
    string State;

public:
    Memento(const string &state) : State(state) {}

    const string &GetState() const { return State; }
};

class Originator
{
private:
    string State;

public:
    Memento CreateMemento()
    {
        Memento m(State);
        return m;
    }

    void SetMemento(const Memento &memento)
    {
        State = memento.GetState();
    }

public:
    void SetState(const string &state) { State = state; }

    const string &GetState() const { return State; }
};

int main()
{
    Originator o;

    o.SetState("1");
    cout << o.GetState() << endl;
    
    Memento m = o.CreateMemento();
    
    o.SetState("2");
    cout << o.GetState() << endl;

    o.SetMemento(m);
    cout << o.GetState() << endl;
}