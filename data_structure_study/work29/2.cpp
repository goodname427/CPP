#include <bits/stdc++.h>
using namespace std;

void get_next(string patt)
{
    int len = patt.length();
    int *next = new int[len + 1];
    next[0] = -1;
    memset(next + 1, 0, (len - 1) * sizeof(int));
    int j = 0, k = -1;
    while (j < len - 1)
    {
        if (k == -1 || patt[j] == patt[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
    for (j = 0; j < len; j++)
        cout << next[j] << " ";
    delete[] next;
}
int main()
{
    string str;
    cin >> str;
    get_next(str);
    return 0;
}
