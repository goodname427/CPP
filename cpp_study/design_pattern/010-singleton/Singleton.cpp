#include "iostream"
#include "mutex"

class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton& other) {}

private:
    static Singleton* Instance;

public:
    // 单线程版本
    static Singleton* Get() 
    {
        if (Instance == nullptr)
        {
            Instance = new Singleton();
        }

        return Instance;
    }

    static std::mutex mtx;

    static Singleton* Get() 
    {
        std::lock_guard<std::mutex> guard(mtx);
        if (Instance == nullptr)
        {
            Instance = new Singleton();
        }

        return Instance;
    }

public:
    void Hello()
    {
        std::cout << "Hello From " << this << std::endl;
    }

};

Singleton* Singleton::Instance = nullptr;

int main()
{
    Singleton::Get()->Hello();
    Singleton::Get()->Hello();
    Singleton::Get()->Hello();
    return 0;
}


