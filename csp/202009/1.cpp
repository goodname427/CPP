#include <bits/stdc++.h>
using namespace std;

struct sp
{
    int i;
    int x;
    int y;
    int dis;
};

inline int get_dis(int X, int Y, int x, int y)
{
    return (X - x) * (X - x) + (Y - y) * (Y - y);
}

bool compare(const sp &l, const sp &r)
{
    return l.dis < r.dis || (l.dis == r.dis && l.i < r.i);
}

int main()
{
    int n, X, Y;
    cin >> n >> X >> Y;
    vector<sp> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].x >> vec[i].y;
        vec[i].i = i + 1;
        vec[i].dis = get_dis(X, Y, vec[i].x, vec[i].y);
    }
    sort(vec.begin(), vec.end(), compare);

    for (int i = 0; i < 3; i++)
    {
        cout << vec[i].i << endl;
    }

    return 0;
}
