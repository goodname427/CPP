#include <iostream>
#include <random>
using namespace std;

#pragma region
//匹配项
struct Match
{
    int index;  //匹配项下标
    int length; //匹配项长度
};
//函数声明 sourceOffset+=partoffset-next[j] partoffset=next[partoffset]+1

void GetOffset(Match *, int, int &, int &);
int PartMatch(string, Match *);

// kmp算法匹配
int KMPMatch(string source, string part)
{
    Match partMatches[part.length()];                       //子匹配项
    int size = PartMatch(part, partMatches);                //获取子匹配项及其长度
    int sourceOffset = 0, partOffset = 0;                   //偏移量
    while (sourceOffset <= source.length() - part.length()) //判断源字串是否匹配完
    {
        if (source[sourceOffset + partOffset] != part[partOffset]) //指定位置字符不等时重新获取偏移量
        {
            GetOffset(partMatches, size, sourceOffset, partOffset);
            // cout << "Source Offset:" << sourceOffset << " Part Offset:" << partOffset << endl;
        }
        else //指定位置字符串相同则继续向后移动
            partOffset++;
        if (partOffset >= part.length()) //匹配完成后跳出循环
            break;
    }
    if (sourceOffset > source.length() - part.length()) //未匹配到
        return -1;
    else
        return sourceOffset;
}
//获取子匹配项
int PartMatch(string part, Match *partMatches)
{
    int size = 0; //匹配项长度
    for (int i = 1; i < part.length(); i++)
    {
        int j; //记录匹配项长度
        for (j = 0; j < part.length(); j++)
        {
            if (part[i + j] != part[j])
                break;
        }
        if (j > 0) //匹配项长度大于1
            partMatches[size++] = {i, j};
    }
    return size;
}
//获取偏移量
void GetOffset(Match *partMatches, int size, int &sourceOffset, int &partOffset)
{
    if (partOffset == 0)
    {
        sourceOffset++;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (partMatches[i].index < partOffset) //匹配项在当前源字串偏移量后且在断点前则满足条件
        {
            sourceOffset += partMatches[i].index;                                                                                                    //源字串偏移量为 子匹配项下标
            partOffset = (partMatches[i].index + partMatches[i].length <= partOffset) ? (partOffset - partMatches[i].index) : partMatches[i].length; //子字串偏移量为 子匹配项长度
            return;
        }
    }
    sourceOffset += partOffset;
    partOffset = 0;
}
#pragma endregion
// abadabaca abac
bool test(string, string,int&);
void RandomString(string &s1, string &s2);
int main()
{
    string s1, s2;
    RandomString(s1, s2);
    int count = 0,pos;
    while (count < 1000 && test(s1, s2,pos))
    {
        if(pos!=-1) count++; 
        RandomString(s1, s2);
    }
    if (count < 1000)
        cout << "失败";
    else
        cout << "成功";
}

int IndexOf(string main, string part)
{
    for (int i = 0; i <= main.length() - part.length(); i++)
    {
        int j;
        for (j = 0; j < part.length(); j++)
        {
            if (main[i + j] != part[j])
                break;
        }
        if (j == part.length())
            return i;
    }
    return -1;
}
bool test(string s1, string s2,int& pos)
{
    //cout<<s1<<endl<<s2<<endl<<endl;
    int r1 = IndexOf(s1, s2);
    int r2 = KMPMatch(s1, s2);
    if(r1!=-1)
    cout<<r1<<" "<<r2<<endl;
    pos=r1;
    return r1 == r2;
}

void RandomString(string &s1, string &s2)
{
    random_device rand;
    int l1 = (rand() % 100)+100, l2 =  (rand() % 5)+5;
    //cout<<l1<<" "<<l2<<endl;
    s1=s2="";
    for (int i = 0; i < l1; i++)
    {
        s1 += (char)((rand() % 26) + 65);
        if(i<l2) s2 += (char)((rand() % 26) + 65);
    }
}