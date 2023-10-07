#include <bits/stdc++.h>
using namespace std;

template <class T>
void cout_vector(vector<T> vec)
{
    for (auto e : vec)
    {
        cout << e << " ";
    }
    cout << endl;
}
template <class T>
void cout_vector(vector<T> vec, void func(T))
{
    for (auto e : vec)
    {
        func(e);
    }
    cout << endl;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void binaryTreePaths(TreeNode *root, string &path, vector<string> &res)
    {
        int len = path.length();
        path.insert(path.length(), (len ? "->" : "") + to_string(root->val));
        cout << path << endl;
        if (!root->left && !root->right)
        {
            res.push_back(path);
        }
        else
        {
            binaryTreePaths(root->left, path, res);
            binaryTreePaths(root->right, path, res);
        }

        path.erase(len);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        string path = "";
        binaryTreePaths(root, path, res);
        return res;
    }
};

int main()
{
    Solution solution;
    // vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> vec1{1, 2};
    vector<int> vec2;
    vector<int> vec3;
    cout_vector(solution.binaryTreePaths(new TreeNode(0)));
    return 0;
}