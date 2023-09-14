#include <bits/stdc++.h>
using namespace std;

struct _tuple
{
    int col;
    int row;
    int val;
};

struct table
{
    _tuple ts[1000];
    int count;
};

void display(table t)
{
    int i;
    for (i = 0; i < t.count; i++)
    {
        cout << t.ts[i].row << " " << t.ts[i].col << " " << t.ts[i].val << endl;
    }
}

int value(table t, int x, int y)
{
    int i;
    for (i = 0; i < t.count; i++)
    {
        if (t.ts[i].col == x && t.ts[i].row == y)
            return t.ts[i].val;
    }
    return 0;
}

void add(table t, table s, int n)
{
    table u;
    u.count = 0;
    int i, j;
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++)
        {
            int v = value(t, i, j) + value(s, i, j);
            if (v != 0)
            {
                u.ts[u.count].col = i;
                u.ts[u.count].row = j;
                u.ts[u.count].val = v;
                u.count++;
            }
        }
    display(u);
}

int main()
{
    table t, s;
    t.count = s.count = 0;
    int n, i, ts, ss;
    cin >> n >> ts >> ss;
    for (i = 0; i < ts; i++)
    {
        int x, y, v;
        cin >> y >> x >> v;
        t.ts[t.count].col = x;
        t.ts[t.count].row = y;
        t.ts[t.count].val = v;
        t.count++;
    }
    for (i = 0; i < ss; i++)
    {
        int x, y, v;
        cin >> y >> x >> v;
        s.ts[s.count].col = x;
        s.ts[s.count].row = y;
        s.ts[s.count].val = v;
        s.count++;
    }
    add(t, s, n);
    return 0;
}
