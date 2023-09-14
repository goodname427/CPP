#include <iostream>
using namespace std;

//函数声明 sourceOffset+=partoffset-next[j] partoffset=next[partoffset]+1

class KMP
{
public:
    KMP(string pattern) : pattern(pattern) { GetNext(); }
    ~KMP(){delete[] dp;}
    // kmp算法匹配
    int Search(string source)
    {
        int sourceOffset = 0, partOffset = 0; //偏移量
        for (; sourceOffset < source.length(); sourceOffset++)
        {
            partOffset = dp[partOffset][source[sourceOffset]];
            if(partOffset==pattern.length()) return sourceOffset-pattern.length()+1;
        }
        return -1;
    }
    static int Search(string source, string pattern)
    {
        return KMP(pattern).Search(source);
    }
private:
    //获取子匹配项
    void GetNext()
    {
        int M = pattern.length();
        // dp[状态][字符] = 下个状态
        dp = new int[M][256]{0};
        // base case
        dp[0][pattern[0]] = 1;
        // 影子状态 X 初始为 0
        int X = 0;
        // 当前状态 j 从 1 开始
        for (int j = 1; j < M; j++)
        {
            for (int c = 0; c < 256; c++)
            {
                if (pattern[j] == c)
                    dp[j][c] = j + 1;
                else
                    dp[j][c] = dp[X][c];
            }
            // 更新影子状态
            X = dp[X][pattern[j]];
        }
    }
    string pattern;
    int (*dp)[256];
};
int main()
{
    KMP kmp("ababac");
    //kmp.DB();
    cout << kmp.Search("ababaababdbababac") << endl;
    return 0;
}