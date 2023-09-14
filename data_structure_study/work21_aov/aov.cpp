#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int mat[MAX][MAX];
string names[MAX];
int n;

void init()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = -1;
}

int get_index(string name)
{
    for (int i = 0; i < n; i++)
        if (names[i] == name)
            return i;
    return -1;
}

void input_map_name()
{
    int m; // n �ڵ��� m ����
    cin >> n >> m;
    init();                     //��ʼ������
    for (int i = 0; i < n; i++) //��¼������ڵ�ļ�ֵ��
    {
        string name;
        cin >> name;
        names[i] = name;
    }
    for (int i = 0; i < m; i++) //�����
    {
        string name1, name2;
        cin >> name1 >> name2;
        mat[get_index(name1)][get_index(name2)] = 1;
    }
}

void input_map()
{
    int m; // n �ڵ��� m ����
    cin >> n >> m;
    init();                     //��ʼ������
    for (int i = 0; i < m; i++) //����
    {
        int x, y;
        cin >> x >> y;
        mat[x - 1][y - 1] = 1;
    }
}

void aov_sort(bool is_name)
{
    int *in = new int[n]; //��¼���
    stack<int> s;
    int count = 0;                   //������
    for (int i = n - 1; i >= 0; i--) //��ʼ�����
    {
        in[i] = 0;
        for (int j = 0; j < n; j++)
            if (mat[j][i] != -1)
                in[i]++;
        if (in[i] == 0) //������Ϊ0����ջ
            s.push(i);
    }
    while (!s.empty())
    {
        int v = s.top(); //��ȡջ��Ԫ��
        s.pop();
        if (is_name)
            cout << names[v] << " "; //���
        else
            cout << v + 1 << " ";   //���
        count++;                    //������+1
        for (int i = 0; i < n; i++) //���������ߵ����
            if (mat[v][i] != -1)
                if ((--in[i]) == 0) //�����ú�Ľڵ�����Ϊ0����ڵ���ջ
                    s.push(i);
    }
    if (count < n) //���������С���ܽڵ�����˵���л�·
        cout << endl
             << "�л�·" << endl;
    delete[] in;
}

int main()
{
    input_map();
    aov_sort(false);
    return 0;
}
/*
6 8
1 2
1 4
1 5
5 6
2 3
2 6
6 3
4 5

12 16
������ƻ���
��ɢ��ѧ
���ݽṹ
�������
���Ե���������
�����ԭ��
����ԭ��
����ϵͳ
�ߵ���ѧ
���Դ���
��ͨ����
��ֵ����
������ƻ��� ��ɢ��ѧ
������ƻ��� ���ݽṹ
��ɢ��ѧ ���ݽṹ
������ƻ��� �������
���ݽṹ ���Ե���������
������� ���Ե���������
��ͨ���� �����ԭ��
���ݽṹ ����ԭ��
���Ե��������� ����ԭ��
���ݽṹ ����ϵͳ
�����ԭ�� ����ϵͳ
�ߵ���ѧ ���Դ���
�ߵ���ѧ ��ͨ����
������ƻ��� ��ֵ����
�ߵ���ѧ ��ֵ����
���Դ��� ��ֵ����

7 10
3 1
4 1
4 2
6 2
5 3
5 4
7 4
6 4
7 5
7 6
*/
