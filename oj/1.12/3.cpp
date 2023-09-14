#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    string *names = new string[n];
    for (int i = 0; i < n; i++)
    {
        string name;
        float temp;
        int is_cough;
        cin >> name >> temp >> is_cough;
        if (temp >= 37.5 && is_cough)
            names[count++] = name;
    }
    for (int i = 0; i < count; i++)
    {
        cout << names[i] << endl;
    }
    cout << count;
    return 0;
}