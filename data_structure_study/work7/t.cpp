#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    int nums[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < 10; i++)
    {
        if (nums[i] % 2 == 0)
            cout << nums[i] << " ";
        else
            s.push(nums[i]);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}