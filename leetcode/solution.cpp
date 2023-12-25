#include <bits/stdc++.h>
#include "solution.h"
using namespace std;

template <class T>
void print(vector<T> vec)
{
    for (auto e : vec)
    {
        cout << e << ' ';
    }
    cout << endl;
}
template <class T>
void print(vector<T> vec, void func(T))
{
    for (auto e : vec)
    {
        func(e);
    }
    cout << endl;
}

int main()
{
    Solution solution;
    // vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> vec1{5,7,7,8,8,10};
    vector<int> vec2;
    vector<int> vec3;
    vector<vector<int>> vec4 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    //                      1 2 3 4 2 1

    
    ListNode *list1 = new ListNode(-9);
    list1->next = new ListNode(3);
    ListNode *list2 = new ListNode(5);
    list2->next = new ListNode(7);
    // cout << 
    solution.mergeTwoLists(list1, list2);
    
    delete list1->next;
    delete list1;
    delete list2->next;
    delete list2;

    return 0;
}