#include <iostream>
using namespace std;

template <class T>
struct Element
{
    int col;
    int row;
    T data;
};
template <class T>
void Compress(T **matrix, int width, int height, T _default, Element<T> **c_matrix, int &c_size)
{
    *c_matrix = new Element<T>[width * height];
    c_size = 0;
    for (int col = 0; col < width; col++)
    {
        for (int row = 0; row < height; row++)
        {
            T *item = (T *)matrix + width * row + col;
            if (*item != _default)
                (*c_matrix)[c_size++] = {col, row, *item};
            item = NULL;
        }
    }
    Element<T> *_c_matrix = new Element<T>[c_size];
    for (int i = 0; i < c_size; i++)
        _c_matrix[i] = (*c_matrix)[i];
    delete[] * c_matrix;
    *c_matrix = _c_matrix;
}

int main()
{
    int m[4][4]{
        {1, 4, 0, 0},
        {1, 0, 0, 0},
        {0, 5, 0, 0},
        {0, 0, 0, 1},
    };
    Element<int> *c_m;
    int c_size;
    Compress<int>((int **)m, 4, 4, 0, &c_m, c_size);
    for (int i = 0; i < c_size; i++)
    {
        cout << c_m[i].col << " " << c_m[i].row << " " << c_m[i].data << endl;
    }
    return 0;
}