#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int get_width_sum(vector<int> array)
    {
        sort(array.begin(), array.end());
        int mod = 1e9 + 7, sum = 0;
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                int sub = array[i] - array[j];
                sum += (sub % mod) * pow(2, i - j - 1);
            }
        }
        return sum;
    }
};

int main()
{
    Solution s;
    vector<int> array = {2, 1, 39, 10};
    cout << s.get_width_sum(array) << endl;
    array = {2, 1, 3};
    cout << s.get_width_sum(array) << endl;
    array = {10, 2, 8, 77, 10023, 9898, 12003, 212312};
    cout << s.get_width_sum(array) << endl;
    return 0;
}
