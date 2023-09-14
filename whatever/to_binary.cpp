#include <bits/stdc++.h>
using namespace std;

string to_binary(int num)
{
    string binary = "";
    int remind;
    while (num)
    {
        remind = num % 2;
        num = (num - remind) / 2;
        binary.insert(binary.begin(), (char)(remind + '0'));
    }
    return binary;
}

string printBin(double num)
{
    string s = "";
    while (num)
    {
        num *= 2;
        s += (char)((int)num + '0');
        num -= (int)num;
        if (s.length() > 32)
            return "ERROR";
    }
    return "0." + s;
}

int main()
{
    cout<<printBin(0.483);
    return 0;
}
