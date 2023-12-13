#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) 
    {
        deque<string> q;
        string temp = "";
        for (char &c : path)
        {
            if (c == '/')
            {
                // 双重斜杠过滤掉
                if (temp.length() == 0)
                {
                    continue;
                }
                else
                {
                    if (temp == "..")
                    {
                        q.pop_back();
                    }
                    else if (temp != ".")
                    {
                        q.push_back(temp);
                    }
                    temp.clear();
                }
            }
            else
            {
                temp.push_back(c);
            }
        }

        if (temp.length() > 0)
        {
            q.push_back(temp);
        }

        string res = "";
        while (!q.empty())
        {
            res += "/" + q.front();
            q.pop_front();
        }

        return res;
    }
};