#include <iostream>
using namespace std;

bool isNum(char c)
{
    return c >= '0' && c <= '9';
}

int my_atoi(string str)
{
    int i = 0;
    long long result = 0;
    int isNeg = 1;
    if (str[0] == '-')
    {
        isNeg = -1;
        i++;
    }
    else if (str[0] == '+')
        i++;
    while (isNum(str[i]))
    {
        result = result * 10 + str[i] - '0';
        if (isNeg==-1 && -1 * result < INT_MIN)
            return INT_MIN;
        else if (result > INT_MAX)
            return INT_MAX;
        i++;
    }
    return result * isNeg;
}

int main()
{
    string c;
    while (getline(cin, c))
        cout << my_atoi(c) << endl;
    return 0;
}