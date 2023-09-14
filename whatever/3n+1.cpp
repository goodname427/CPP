#include <bits/stdc++.h>
using namespace std;

bool is_valid(int n)
{
    cout<<n<<" ";
    if(n==1) return true;
    if(n%2==0)
    {
        return is_valid(n/2);
    }
    else
    {
        return is_valid(3*n+1);
    }
}

int main()
{
    for(int i=1;i<10;i++)
    {
        is_valid(i);
        cout<<endl<<endl;
    }
    return 0;
}
