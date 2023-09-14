#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

typedef struct S
{
    char elem[100];
} S;

typedef struct BiTNode
{
    char data[100];
    struct BiTNode *lchild, *rchild;

} BiTNode, *BiTree;
char zimu[26] = {'a', 'b', 'c', 'd', 'y', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'e', 'z'};
int q;
char b[1001];
S a[1000];
char ch;
BiTree t = NULL;

BiTree creat(char *ch, BiTree &t)
{
    if (t == NULL)
    {
        t = new BiTNode;
        strcpy(t->data, ch);
        t->lchild = t->rchild = NULL;
    }
    else if (strcmp(ch, t->data) > 0)
        t->rchild = creat(ch, t->rchild);
    else
        t->lchild = creat(ch, t->lchild);
    return t;
}

void Trave(BiTree t)
{
    if (t == NULL)
        return;
    else
    {
        Trave(t->lchild);
        Trave(t->rchild);
        cout << t->data << " ";
    }
}

int ss = 0;
char sh[100];
int s = 0, x = 0;

int sreach(BiTree t, char *b)
{
    if (x == 1)
        return 1;

    if (t == NULL)
        return 0;
    if (strcmp(b, t->data) == 0)
    {
        strcpy(sh, t->data);
        x = 1;
        return 1;
    }

    if (strcmp(b, t->data) > 0)
        sreach(t->rchild, b);

    if (strcmp(b, t->data) < 0)
    {
        sreach(t->lchild, b);
    }
}

void delet(char *r, int i) //删一个字符
{
    int e;

    for (e = i; e < strlen(r); e++)
    {
        r[e] = r[e + 1];
    }
}
void add(char *r, int i, char th) //加一个字符
{
    int e;
    for (e = strlen(r) - 1; e >= i; e--)
    {

        r[e + 1] = r[e];
    }
    r[i] = th;
}

char r[1001];
int main()
{

    int i = 0;
    while (cin >> a[i].elem)
    {
        if (a[i].elem[0] == '#')
            break;
        q++;
        i++;
    }
    i = 0;
    while (i < q)
        creat(a[i++].elem, t);

    Trave(t); //后序遍历
    cout << endl;
    while (cin >> b)
    {
        x = 0;
        ss = 0;
        if (b[0] == '#')
            break;

        strcpy(r, b);
        sreach(t, b);
        if (x == 1) // 相匹配
        {
            ss = 1;
            cout << b << " is correct";
        }
        int i, z;
        if (x == 0)
        {
            cout << b << ":";
            r[strlen(r) + 1] = '\0';
            for (i = 0; i < strlen(b); i++) //替换一个字符后相匹配
            {
                for (z = 0; z < 26; z++)
                {
                    r[i] = zimu[z];
                    sreach(t, r);
                    if (x == 1)
                    {
                        cout << " " << sh;
                        ss = 1;
                        strcpy(r, b);
                        x = 0;
                        continue;
                    }
                    strcpy(r, b);
                    x = 0;
                }
            }
            for (i = 0; i <= strlen(b); i++) //加一个字符后相匹配
            {

                for (z = 0; z < 26; z++)
                {

                    strcpy(r, b);
                    x = 0;
                    add(r, i, zimu[z]);

                    sreach(t, r);
                    if (x == 1)
                    {
                        cout << " " << sh;
                        ss = 1;
                        strcpy(r, b);
                        x = 0;
                        continue;
                    }
                }
            }
            for (i = 0; i < strlen(b); i++) //减一个字符后相匹配
            {
                x = 0;

                strcpy(r, b);

                delet(r, i);

                sreach(t, r);
                if (x == 1)
                {
                    cout << " " << sh;
                    ss = 1;
                    strcpy(r, b);
                    x = 0;
                    continue;
                }
            }
        }

        if (ss == 0)
            cout << " ";

        cout << endl;
    }
}