#include "iostream"
using namespace std;

class Tool
{
public:
    template <class Type,class T>
    static void TemplateFun(Type s)
    {
        cout << s << endl;
    }
};

int main()
{
    Tool t;
    Tool::TemplateFun<int,Tool>(1);
    return 0;
}