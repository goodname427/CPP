#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char, int> pMap;
        unordered_map<string, int> sMap;

        int pIdx = 0;
        int sIdx = 0;
        int j = 0;

        int start = -1;
        string word;
        for (int i = 0; i < s.length(); i++)
        {
            if (start == -1 && s[i] != ' ')
            {
                start = i;
            }
            else if (s[i] == ' ' && start != -1)
            {
                
                word = s.substr(start, i - start);
                start = -1;
                if (sMap.find(word) == sMap.end())
                    sMap.insert({word, sIdx++});
                if (pMap.find(pattern[j]) == pMap.end())
                    pMap.insert({pattern[j], pIdx++});

                if (sMap[word] != pMap[pattern[j]])
                    return false;
                j++;
            }
        }

        if (start != -1)
        {
            word = s.substr(start, s.length() - start);
            if (sMap.find(word) == sMap.end())
                sMap.insert({word, sIdx++});
            if (pMap.find(pattern[j]) == pMap.end())
                pMap.insert({pattern[j], pIdx++});

            if (sMap[word] != pMap[pattern[j]])
                return false;
        }

        return true;
    }
};