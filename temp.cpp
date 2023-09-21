#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(const vector<int> &nums)
    {
        int eor = 0;
        for (auto i : nums)
            eor ^= i;
        
        int filter = eor & (-eor);
        vector<int> result(2, eor);
        for (auto i : nums)
        {
            if (filter & i)
                result[0] ^= i;
            else
                result[1] ^= i;
        }
        return result;
    }
};

int main()
{
    cout << (int)'a';
}
