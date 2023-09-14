#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> v;
    v.push_back("Hello C++");
    v.push_back("Hello Python");
    v.push_back("Hello Java");
    v.push_back("Hello C#");
    for(auto i=v.begin();i!=v.end();i++)
    {
        cout<<*i<<endl;
    }
    
    return 0;
}