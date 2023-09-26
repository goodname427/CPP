#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.length() <= 1)
            return s.length();

        int start = 0, max_l = 0, i = 1;
        unordered_map<char, int> has;
        has.insert(pair<char, int>(s[0], 0));

        for (; i < s.length(); i++)
        {
            auto f = has.find(s[i]);
            if (f != has.end())
            {
                max_l = max(max_l, i - start);
                int j = start;
                start = f->second + 1;
                for (; j <= f->second; j++)
                    has.erase(s[j]);
            }
            
            has.insert(pair<char, int>(s[i], i));
        }

        return max(max_l, i - start);
    }
};
int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("bbbbb");
}
