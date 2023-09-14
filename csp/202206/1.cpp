#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    //平均值
    vector<int> vec(n, 0);
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        sum += vec[i];
    }
    double ave = sum / n;
    //方差
    sum = 0;
    for (auto e : vec)
    {
        sum += (e - ave) * (e - ave);
    }
    double sqrt_d = sqrt(sum / n);

    for (auto e : vec)
    {
        cout << (e - ave) / sqrt_d << endl;
    }
    return 0;
}
