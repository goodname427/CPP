#include <bits/stdc++.h>
#include "../util/cvectorop"
using namespace std;

string randomly_str(int max)
{
    vector<int> vec = randomly_vec(max, 10);
    string res = "";
    for (auto e : vec)
        res += e + 'a';
    return res;
}

vector<int> get_next(string pattern)
{
    vector<int> next(pattern.length());
    next[0] = -1;
    int j = 0, k = -1;

    while (j < pattern.length() - 1)
    {
        if (k == -1 || pattern[j] == pattern[k])
        {
            next[++j] = ++k;
        }
        else
        {
            k = next[k];
        }
    }
    return next;
}

int kmp(string source, string pattern)
{
    if (source.length() < pattern.length())
        return -1;

    vector<int> next = get_next(pattern);

    int i = 0, j = 0;
    while (i < (int)source.length() && j < (int)pattern.length())
    {
        if (j == -1 || source[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    return j == pattern.length() ? i - j : -1;
}

int main()
{
    int t = 10;
    while (t--)
    {
        string source = randomly_str(30);
        string pattern = randomly_str(source.length());
        
        int index = kmp(source, pattern);
        
        if (index == -1 || pattern.length() <= 4)
        {
            t++;
            continue;
        }

        cout << source << endl;

        for (int i = 0; i < index; i++)
            cout << " ";

        
        cout << pattern << endl;
        cout << endl;
    }
    return 0;
}
