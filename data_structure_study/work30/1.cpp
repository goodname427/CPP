#include <bits/stdc++.h>
using namespace std;

void delete_same(string &str)
{
    if (str.length() == 0)
        return;
    vector<string::iterator> ds;
    int *has_in = new int[str.length()], i = 1;
    memset(has_in, 0, str.length() * sizeof(int));
    string::iterator it = str.begin();
    vector<string::iterator>::iterator _it;
    for (it++; it != str.end(); it++, i++)
    {
        if (*it == *(it - 1))
        {
            ds.push_back(it);
            has_in[i] = 1;
            if (!has_in[i - 1])
            {
                ds.push_back(it - 1);
                has_in[i - 1] = 1;
            }
        }
    }
    if (ds.size() <= 0)
        return;
    for (_it = ds.begin(); _it != ds.end(); _it++)
        str.erase(*_it);
    delete_same(str);
}

int main()
{
    string str;
    cin >> str;
    delete_same(str);
    cout << str;
    return 0;
}
