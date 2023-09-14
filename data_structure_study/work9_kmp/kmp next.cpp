#include <iostream>
#include "ctest"
using namespace std;

class KMP
{
public:
    KMP(string pattern) : pattern(pattern) { GetNext(); }
    ~KMP() { delete[] next; }
    // kmp算法匹配
    int Search(string source)
    {
        int i = 0, j = 0; //偏移量
        while (i < (int)source.length() && j < (int)pattern.length())
        {
            if (j == -1 || source[i] == pattern[j])
            {
                i++;
                j++;
            }
            else
                j = next[j]; // j回退
        }
        if (j >= (int)pattern.length())
            return i - pattern.length(); //匹配成功，返回子串的位置
        else
            return -1; //没找到
    }
    int *Searches(string source, int &size)
    {
        auto indexs = new int[source.length()];
        size = 0;
        int i = 0, j = 0; //偏移量
        while (1)
        {
            while (i < (int)source.length() && j < (int)pattern.length())
            {
                if (j == -1 || source[i] == pattern[j])
                {
                    i++;
                    j++;
                }
                else
                    j = next[j]; // j回退
            }
            if (j >= (int)pattern.length())
            {
                indexs[size++] = i - pattern.length(); //匹配成功，记录子串的位置
                i = i - pattern.length() + 1;//i回退
                j = 0;//j回退
            }
            else
                break;//退出
        }
        return indexs;
    }
    static int Search(string source, string pattern)
    {
        return KMP(pattern).Search(source);
    }

private:
    //获取子匹配项
    void GetNext()
    {
        next = new int[pattern.length()];
        int j = 0, k = -1;
        next[0] = -1;
        while (j < pattern.length() - 1)
        {
            if (k == -1 || pattern[j] == pattern[k])
            {
                j++;
                k++;
                next[j] = k;
            }
            else
                k = next[k]; //神之一手！！！
        }
    }
    string pattern;
    int *next;
};
int main()
{
    KMP kmp("aba");

    cout << kmp.Search("asdaba") << endl;

    int size;
    auto indexs = kmp.Searches("abacaba", size);

    for (int i = 0; i < size; i++)
        cout << indexs[i] << " ";
    return 0;
}