#include "lib.cpp"

class Application : public Library
{
protected:
    virtual void Tick(int time) override
    {
        // do someting
    }

    virtual bool ShouldContinue(int time) override
    {
        return false;
    }
};

int main()
{
    Library *lib = new Application();

    lib->Run();

    delete lib;

    return 0;
}
