#include <iostream>
#include <stdio.h>
using namespace std;

#define M 4
#define N 4

struct Node
{
    int col;
    int row;
    int data;
};

struct Table
{
    Node nodes[M * N];
    int size;
};

Table CreatTable(int matrix[M][N])
{
    Table t;
    t.size = 0;
    for (int row = 0; row < M; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (matrix[row][col] != 0)
            {
                t.nodes[t.size++] = {col, row, matrix[row][col]};
            }
        }
    }
    return t;
}

Table TranTable(Table t)
{
    Table b;
    b.size = 0;
    for (int j = 0; j < N;)
    {
        for (int i = 0; i < t.size; i++)
        {
            if (t.nodes[i].col == j)
                b.nodes[b.size++] = {t.nodes[i].row, t.nodes[i].col, t.nodes[i].data};
        }
        j++;
    }
    return b;
}

void PrintTable(Table t)
{
    printf("SIZE:%d", t.size);
    printf("\tCOl\tROW\tDATA\n");
    for (size_t i = 0; i < t.size; i++)
    {
        printf("\t%d\t%d\t%d\n", t.nodes[i].col, t.nodes[i].row, t.nodes[i].data);
    }
}

int main()
{
    int m[M][N] = {
        {0, 0, 1, 2},
        {0, 0, 0, 2},
        {1, 0, 0, 2},
        {2, 2, 2, 2},
    };
    Table t = CreatTable(m);
    t = TranTable(t);
    PrintTable(t);
    return 0;
}
/*
        {0, 0, 1, 2},
        {0, 0, 0, 2},
        {1, 0, 0, 2},
        {2, 2, 2, 2},
*/