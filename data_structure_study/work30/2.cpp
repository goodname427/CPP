#include <bits/stdc++.h>
using namespace std;

struct tree
{
    tree*left;
    tree*right;
    int val;
};

tree* creat(string& pre)
{
    if(pre.length()<=0) 
        return NULL;
    int index=pre.find(',');
    string c=index==-1?pre:pre.substr(0,index);
    pre=index==-1?"":pre.substr(index+1,pre.length()-index-1);

    if(c[0]=='#')
        return NULL;
    tree* root=new tree;
    root->val=atoi(c.c_str());
    root->left=creat(pre);
    root->right=creat(pre);
    return root;
}

int get_depth(tree* root)
{
    if(root==NULL)
        return 0;
    int l=get_depth(root->left);
    int r=get_depth(root->right);
    return min(l,r)+1;
}

int main()
{
    int i,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        string str;
        cin>>str;
        tree* root=creat(str);
        cout<<get_depth(root)<<endl;
    }
    return 0;
}
