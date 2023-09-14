#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    float sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int count;
        cin >> count;
        if (count <= 70)
            sum += 0.1;
        else
        {
            sum += ceil(count / 70.0) * 0.1;
        }
    }
    printf("%0.1f", sum);
    return 0;
}