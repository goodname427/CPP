#include <algorithm>
#include <iostream>
using namespace std;
    
struct t77
{
    int no;
    int grade;
};

bool compare(struct t77 t1,struct t77 t2)
{
    return t1.grade>=t2.grade;   
}

int main()
{
    struct t77 p[]={{1,23},{2,34},{3,10}};
    sort(p,p+3,compare);
    for(int i=0;i<3;i++)
    {
        cout<<p[i].no<<" "<<p[i].grade<<endl;
    }
    return 0;
}