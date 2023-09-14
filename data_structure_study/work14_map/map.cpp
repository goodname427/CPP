#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node
{
    Point point;
    Node *parent;
    vector<Node *> children;

    Node(Point point) : point(point)
    {
        children = vector<Node *>();
    }

    void AddChild(Point point)
    {
        auto child = new Node(point);
        child->parent = this;
        children.push_back(child);
    }
};

struct Point
{
    int x;
    int y;
    int f;
    int g;
    int h;
};

int main()
{
    int map[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    return 0;
}