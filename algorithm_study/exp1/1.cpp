#include <bits/stdc++.h>
using namespace std;

// 获取一个数的所有位上的数字
vector<int> get_bits(int number)
{
    vector<int> bits;
    while (true)// 获取该数字上的每一位数
    {
        bits.push_back(number % 10);
        number /= 10;
        if (number <= 0)
            return bits;
    }
}
// 判断该数字是否包含7或者是7的倍数，如果是返回true，否则返回false
bool has_7(int number)
{
    vector<int> bits = get_bits(number);
    for (int i = 0; i < bits.size(); i++)// 判断是否包含7
    {
        if (bits[i] == 7)
            return true;
    }
    return number % 7 == 0;// 判断是否是7的倍数
}

int main()
{
    int N, count = 0, number = 0, list[5] = {0};
    cin >> N;
    while (count < N)
    {
        number++;// 获取下一位要数的数
        if (has_7(number))// 如果该数满足7的条件则跳过，并将跳过的同学跳过的数的数量+1
        {
            list[(number - 1) % 5]++;
        }
        else // 否则将已数过的数的数量+1
        {
            count++;
        }
    }
    //输出
    for (int i = 0; i < 5; i++) 
    {
        cout << list[i] << endl;
    }
    cout << number;
    return 0;
}
