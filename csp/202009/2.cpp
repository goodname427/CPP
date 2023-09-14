#include <bits/stdc++.h>
using namespace std;

inline int is_in(int x, int y, int xl, int yd, int xr, int yu)
{
    return x >= xl && x <= xr && y >= yd && y <= yu;
}

int main()
{
    int n, k, t, xl, yd, xr, yu;
    cin >> n >> k >> t >> xl >> yd >> xr >> yu;
    int stay = 0, pass = 0;
    while (n--)
    {
        int stay_t = 0, x, y, is_stay = 0, is_pass = 0;
        for (int i = 0; i < t; i++)
        {
            cin >> x >> y;
            if (is_in(x, y, xl, yd, xr, yu))
            {
                stay_t++;
                is_pass = 1;
                if (stay_t >= k)
                    is_stay = 1;
            }
            else
            {
                stay_t = 0;
            }
        }
        stay += is_stay;
        pass += is_pass;
    }
    cout << pass << endl
         << stay;
    return 0;
}
