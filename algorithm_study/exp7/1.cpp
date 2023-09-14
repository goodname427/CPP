#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int horizontal(vector<int> &vec)
{
    int count = 0, has = 0;
    try
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] > 0)
            {
                if (!has)
                {
                    has = 1;
                    count++;
                }
                vec[i]--;
            }
            else
                has = 0;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return count;
}

int vertical(vector<int> &vec, int i)
{
    vec[i] = 0;
    return 1;
}

int get_min(vector<int> vec)
{
    //终止条件
    int i;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] != 0)
            break;
    }
    if (i == vec.size())
        return 0;

    vector<int> _vec = vec;
    int min = horizontal(_vec) + get_min(_vec);
    for (i = 0; i < vec.size(); i++)
    {
        _vec = vec;
        if (_vec[i] == 0)
            continue;
        int temp = vertical(_vec, i) + get_min(_vec);
        if (temp < min)
            min = temp;
    }
    return min;
}

int main()
{
    vector<int> vec;
    //输入
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    cout << get_min(vec);

    return 0;
}
/*
5
2 1 2 5 1
*/