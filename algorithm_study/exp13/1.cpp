#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, m, n;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int wash1 = 0, wash2 = 0; //记录两个洗衣房的排队时间
        int *vec = new int[n];    //所有人的洗衣时间
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        //排序
        sort(vec, vec + n);
        //从大到小进行排队
        for (int i = n - 1; i >= 0; i--)
        {
            //选择当前排队时间短的队伍进行排队
            if (wash1 < wash2)
                wash1 += vec[i];
            else
                wash2 += vec[i];
        }
        cout << (max(wash1, wash2) <= m) << endl;
        delete[] vec;
    }

    return 0;
}
