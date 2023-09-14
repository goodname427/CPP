#include <iostream>
using namespace std;

void Compress(int **matrix, int size, int **c_matrix, int &c_size)
{
    c_size = 0;
    *c_matrix = new int[(size * size + size) / 2];
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j <= i; j++)
            (*c_matrix)[c_size++] = *((int *)matrix + size * i + j);
        ;
    }
}

int main()
{
    int matrix[4][4] =
        {
            {1, 2, 3, 4},
            {2, 2, 3, 4},
            {3, 3, 3, 4},
            {4, 4, 4, 4}};
    int *c_matrix = NULL, c_size;
    Compress((int **)matrix, 4, &c_matrix, c_size);
    for (int i = 0; i < c_size; i++)
        cout << c_matrix[i] << " ";
    delete[] c_matrix;
    return 0;
}