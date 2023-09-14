#include <iostream>
using namespace std;

void coinQues(int coin[8])
{
    int c, _c, n = 0;
    if (coin[0] + coin[1] + coin[2] != coin[3] + coin[4] + coin[5])
    {
        n = 7;
        int c1 = 4, c2 = 5, c3 = 3, c4 = 1, c5 = 2, c6 = 0;
        if (coin[0] + coin[1] + coin[2] > coin[3] + coin[4] + coin[5])
        {
            c1 = 0, c2 = 2, c3 = 1, c4 = 3, c5 = 5, c6 = 4;
        }
        c = c3, _c = c6;
        if (coin[0] + coin[4] == coin[1] + coin[3])
        {
            c = c2, _c = c5;
        }
        else if (coin[0] + coin[4] > coin[1] + coin[3])
        {
            c = c1, _c = c4;
        }
    }
    else
    {
        c = 7, _c = 6;
        if (coin[6] > coin[7])
        {
            c = 6, _c = 7;
        }
    }
    if (coin[c] > coin[n])
        cout << c << " H";
    else
        cout << _c << " L";
}

int main()
{
    int coin[8] = {1, 1, 1, 1, 1, 2, 1, 1};
    coinQues(coin);
    return 0;
}