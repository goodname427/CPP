#include <bits/stdc++.h>
using namespace std;

struct student
{
    int y;
    int result;
    int left;
    int right;
    int left_self;
};

bool compare(const student &l, const student &r)
{
    return l.y < r.y;
}

int main()
{
    int m;
    cin >> m;
    vector<student> vec(m);
    for (int i = 0; i < m; i++)
        cin >> vec[i].y >> vec[i].result;

    sort(vec.begin(), vec.end(), compare);

    vector<student>::iterator current = vec.begin();
    vector<vector<student>::iterator> remove;

    for (int i = 1; i < m; i++)
    {
        if (vec[i].y != vec[i - 1].y)
        {
            vec[i].left = vec[i - 1].left + vec[i - 1].left_self + !vec[i - 1].result;
        }
        else
        {
            vec[i].left = vec[i - 1].left;
            vec[i].left_self += !vec[i - 1].result + vec[i - 1].left_self;
        }

        vec[m - i - 1].right = vec[m - i].right + vec[m - i].result;
    }

    //cout << endl;
    pair<int, int> max = pair<int, int>(-1, -1);
    for (int i = 0; i < m; i++)
    {
        int x = vec[i].left + vec[i].right + vec[i].result;
        //cout << vec[i].y << " " << x << endl;
        if (max.second < x || (max.second == x && max.first < vec[i].y))
            max = pair<int, int>(vec[i].y, x);
    }
    cout << max.first;
    return 0;
}
