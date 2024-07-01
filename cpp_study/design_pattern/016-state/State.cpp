template<class TInst>
class Singleton
{
private:
    static TInst* Instance;

public:
    static TInst* Get()
    {
        if (Instance == nullptr)
        {
            Instance = new TInst();
        }

        return Instance;
    }
};

template<class TInst>
static TInst* Singleton<TInst>::Instance = nullptr;

class State
{
public:
    State* Next = nullptr;

    virtual void DoThis() = 0;
    virtual void DoThat() = 0;
};



class StartState : public State, public Singleton<StartState>
{
    virtual void DoThis() override
    {
        Next = CloseState::Get();
    }

    virtual void DoThat() override
    {
        Next = CloseState::Get();
    }
};


class CloseState : public State, public Singleton<CloseState>
{
    virtual void DoThis() override 
    {
        Next = StartState::Get();
    }

    virtual void DoThat() override
    {
        Next = StartState::Get();
    }
};


class StateProcessor
{
public:
    State* Current;

    StateProcessor(State* initState) : Current(initState) {}

    void DoThis() 
    {
        Current->DoThis();
        Current = Current->Next;
    }

    void DoThat()
    {
        Current->DoThat();
        Current = Current->Next;
    }
};