#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

struct lt
{
    int no;
    vector<int> city;
};

int mat[MAX][MAX];
int n;

int main()
{
    int i, j, k, total = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> mat[j][i];
    lt *citys = new lt[n];
    int *where = new int[n];
    for (i = 0; i < n; i++)
    {
        where[i] = i;
        citys[i].no = i;
        citys[i].city.push_back(i);
    }

    for (i = 0; i < n; i++)
        for (j = i+1; j < n; j++)
        {
            if (mat[i][j])
            {
                citys[where[j]].no = -1;
                int _where=where[j];
                for (k = 0; k < citys[_where].city.size(); k++)
                {
                    where[citys[_where].city[k]] = where[i];
                    citys[where[i]].city.push_back(citys[_where].city[k]);
                }
            }
        }
    for (i = 0; i < n; i++)
        if (citys[i].no != -1)
            total++;
    cout << total;
    return 0;
}
