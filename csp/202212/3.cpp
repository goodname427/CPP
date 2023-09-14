#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415

int Q[8][8];
int M[8][8];
double M_[8][8];
int n;
int T;

inline void print(double mat[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

inline void print(int mat[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

inline void input_Q()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> Q[i][j];
}

inline void input_M()
{
    memset(M, 0, sizeof(int) * 64);
    int step = 0, i = 0, j = 0, c = n;
    while (c--)
    {
        cin >> M[i][j];
        switch (step)
        {
        case 0: // 右
            j++;
            if (i == 0)
                step = 1;
            else
                step = 2;
            break;
        case 1: // 左下
            i++;
            j--;
            if (i == 7)
                step = 0;
            else if (j == 0)
                step = 3;
            break;
        case 2: // 右上
            i--;
            j++;
            if (j == 7)
                step = 3;
            else if (i == 0)
                step = 0;
            break;
        case 3: // 下
            i++;
            if (j == 0)
                step = 2;
            else
                step = 1;
        default:
            break;
        }
    }
}

inline void trans_M()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            M[i][j] *= Q[i][j];
        }
    }
}

inline double a(int u)
{
    return u == 0 ? sqrt(0.5) : 1;
}

inline void get_M_()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            double total = 0;
            for (int u = 0; u < 8; u++)
            {
                for (int v = 0; v < 8; v++)
                {
                    total += a(u) * a(v) * M[u][v] * cos(0.125 * PI * (i + 0.5) * u) * cos(0.125 * PI * (j + 0.5) * v);
                }
            }
            M_[i][j] = total / 4;
        }
    }
}

inline int clamp(int val)
{
    if (val > 255)
        return 255;
    if (val < 0)
        return 0;
    return val;
}

inline void trans_M_()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            M_[i][j] = clamp(round(M_[i][j] + 128));
        }
    }
}

int main()
{
    input_Q();
    cin >> n >> T;
    input_M();
    if (T == 0)
    {
        print(M);
        return 0;
    }
    trans_M();
    if (T == 1)
    {
        print(M);
        return 0;
    }
    get_M_();
    trans_M_();
    print(M_);

    return 0;
}
/*
 1  2  3  4  5  6  7  8
 9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
 1  2  6  7 15 16 28 29
 3  5  8 14 17 27 30 43
 4  9 13 18 26 31 42 44
10 12 19 25 32 41 45 54
11 20 24 33 40 46 53 55
21 23 34 39 47 52 56 61
22 35 38 48 51 57 60 62
36 37 49 50 58 59 63 64
*/