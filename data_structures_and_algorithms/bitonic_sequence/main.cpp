#include <bits/stdc++.h>
#include "../util/crand"
#include "../util/cvectorop"
using namespace std;

static vector<int> default_seq { 5, 3, 2, 1, 4, 6, 6, 12 };

vector<int> generate_seq(int n)
{
    int sign = random(0, 1) * 2 - 1; // -1 or 1
    vector<int> seq(n * 2);
    int start = random(0, 100);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                seq[0] = start;
            }
            else
            {
                seq[i * n + j] = seq[i * n + j - 1] + sign * random(0, 10);
            }
        }
        sign = -sign;
    }

    return seq;
}

void get_min_max(int a, int b, int& out_min, int& out_max)
{
    if (a >= b)
    {
        out_max = a;
        out_min = b;
    }
    else
    {
        out_max = b;
        out_min = a;
    }
}

void bitonic_merge(vector<int>& seq, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }

    int n = (end - begin + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        get_min_max(seq[begin + i], seq[begin + i + n], seq[begin + i], seq[begin + i + n]);
    }

    // print(seq, begin, end);
    // getchar();

    bitonic_merge(seq, begin, begin + n - 1);
    bitonic_merge(seq, begin + n, end);
}

void bitonic_merge(vector<int>& seq)
{
    if (seq.size() == 0)
    {
        return;
    }

    bitonic_merge(seq, 0, seq.size() - 1);
}

int main()
{
    auto seq = generate_seq(4);
    cout << "before sort: ";
    print(seq);

    bitonic_merge(seq);
    cout << "after sort: ";
    print(seq);
    return 0;
}
