#include <bits/stdc++.h>
using namespace std;

int get_max(int all)
{
    return all / 2;//全为鸡时数量最多
}

int get_min(int all)
{
    return all / 4 + (all % 4 != 0 ? 1 : 0);// 尽可能的都为兔子时数量最少
}

int main()
{
    int a;
    cin >> a;
    if (a % 2 != 0) // 如果a为，则没有满足条件的数
    {
        cout << "0 0";
    }
    else
    {
        cout << get_min(a) << " " << get_max(a);
    }
    return 0;
}
