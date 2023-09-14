#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s;
    unordered_map<int,int> count_list;
    pair<int,int> max=pair(-1,0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        count_list[s]++;
        if(count_list[s]>max.second)
        {
            max.first=s;
            max.second=count_list[s];
        }
    }
    cout<<max.first;
    return 0;
}
