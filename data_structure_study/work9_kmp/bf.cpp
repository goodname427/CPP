#include <iostream>
#include <vector>
#include <list>
using namespace std;

int IndexOf(string main, string part)
{
    for (int i = 0; i <= main.length() - part.length(); i++)
    {
        int j;
        for (j = 0; j < part.length(); j++)
        {
            if (main[i + j] != part[j])
                break;
        }
        if (j == part.length())
            return i;
    }
    return -1;
}

list<int> IndexsOf(string main, string part)
{
    list<int> indexs;
    for (int i = 0; i <= main.length() - part.length(); i++)
    {
        int j;
        for (j = 0; j < part.length(); j++)
        {
            if (main[i + j] != part[j])
                break;
        }
        if (j == part.length())
            indexs.push_back(i);
    }
    return indexs;
}

int main()
{
    cout << IndexOf("acddsasdcd", "cd")<<endl<<endl;
    auto indexs = IndexsOf("acddhkasdjhqwyduqihdkjasbcnbxzcahdasjkdhoiwqduieyfuhjkcgasjkjxhsuduhcudgchjzkdygchsxbadhgacxbjscdasdcd", "udu");
    cout<<"Times:"<<indexs.size()<<endl<<"Pos:";
    for (auto it = indexs.begin(); it != indexs.end(); it++)
        cout << *it << " ";
    return 0;
}