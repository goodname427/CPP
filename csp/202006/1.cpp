#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x;
    int y;
    char type;
};

inline int get_val(int a, int b, int c, const point &p)
{
    return (a + b * p.x + c * p.y) * (p.type == 'A' ? 1 : -1);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<point> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i].x >> vec[i].y >> vec[i].type;

    int a, b, c, first;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        int j;
        for (j = 0; j < n; j++)
        {
            if (j == 0)
                first = get_val(a, b, c, vec[j]);
            if (get_val(a, b, c, vec[j]) * first < 0)
                break;
        }
        cout << (j == n ? "Yes" : "No") << endl;
    }

    return 0;
}
/*
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
0 2 -3
-3 0 2
-3 1 1

3 1
-1 0 A
1 0 B
-2 0 B
0 1 1
*/