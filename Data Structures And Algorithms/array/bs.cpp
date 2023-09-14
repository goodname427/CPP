#include <bits/stdc++.h>
#include "../util/cvectorop"
using namespace std;

int binary_search(int target, vector<int> &vec, int start, int end)
{
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    if (target == vec[mid])
        return mid;
    if (target < vec[mid])
        return binary_search(target, vec, start, mid - 1);
    return binary_search(target, vec, mid + 1, end);
}

int bs_left(int target, vector<int> &vec, int start, int end)
{
    int left = -1;

    if (start > end)
        return left;

    int mid = (start + end) / 2;
    if (vec[mid] >= target)
    {
        left = mid;
        auto res = bs_left(target, vec, start, mid - 1);
        if (res != -1)
            left = res;
    }
    else
    {
        left = bs_left(target, vec, mid + 1, end);
    }

    return left;
}

vector<int> bs_local_min(vector<int> &vec, int start, int end)
{
    auto res = vector<int>();
    if (vec.size() < 3 || start > end)
        return res;

    int mid = (start + end) / 2;

    if (mid >= 0 && mid < vec.size() && (mid + 1 >= vec.size() || vec[mid] < vec[mid + 1]) && (mid - 1 < 0 || vec[mid] < vec[mid - 1]))
    {
        res.push_back(mid);
        for (auto r : bs_local_min(vec, start, mid - 2))
            res.push_back(r);
        for (auto r : bs_local_min(vec, mid + 2, end))
            res.push_back(r);
    }
    else
    {
        for (auto r : bs_local_min(vec, start, mid - 1))
            res.push_back(r);
        for (auto r : bs_local_min(vec, mid + 1, end))
            res.push_back(r);
    }
    sort(res.begin(), res.end());
    return res;
}

vector<int> local_min(vector<int> &vec)
{
    vector<int> res;

    if (vec.size() < 3)
        return res;

    for (int i = 0; i < vec.size(); i++)
    {
        if (((i + 1 >= vec.size() || vec[i] < vec[i + 1]) && (i - 1 < 0 || vec[i] < vec[i - 1])))
            res.push_back(i);
    }
    return res;
}

void test1()
{
    auto vec = sorted_vec(20, 5);
    print(vec);
    int target;
    while (cin >> target)
        cout << bs_left(target, vec, 0, vec.size());
}

void test2()
{
    int times = 10000;
    while (times--)
    {
        auto vec = unique_vec(200, 100);
        // print(vec);
        auto res1 = bs_local_min(vec, 0, vec.size());
        auto res2 = local_min(vec);
        // print(res1);
        // print(res2);
        if (!equal(res1, res2))
        {
            print(vec);
            print(res1);
            print(res2);
            cout << "error" << endl;
        }
    }
}

int main()
{ 
    test2();
    return 0;
}
