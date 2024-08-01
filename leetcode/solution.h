#include <bits/stdc++.h>
using namespace std;


class UnionSetNode
{
public:
    string key;
    UnionSetNode* parent;

    UnionSetNode(const string& key) : key(key), parent(this)
    {}
};

class UnionSet
{
    vector<UnionSetNode*> tempPath;
    unordered_map<string, UnionSetNode*> nodes;

    UnionSetNode* findRoot(UnionSetNode* node)
    {
        UnionSetNode* root = node;
        tempPath.clear();
        while (root->parent != root)
        {
            tempPath.push_back(root);
            root = root->parent;
        }

        for (auto pathNode : tempPath)
        {
            pathNode->parent = root;
        }

        return root;
    }
public:
    ~UnionSet()
    {
        for (auto node : nodes)
        {
            delete node.second;
        }
    }

    void Insert(const string& key)
    {
        if (nodes.find(key) == nodes.end())
        {
            nodes.emplace(key, new UnionSetNode(key));
        }
    }

    string findRoot(const string& key)
    {
        return findRoot(nodes[key])->key;
    }

    void Union(const string& first, const string& last)
    {
        UnionSetNode* firstNode = nodes[first];
        UnionSetNode* lastNode = nodes[last];

        UnionSetNode* firstRoot = findRoot(firstNode);
        UnionSetNode* lastRoot = findRoot(lastNode);

        if (firstRoot == lastRoot)
        {
            return;
        }
        else
        {
            if (firstRoot->key.compare(lastRoot->key) < 0)
            {
                lastRoot->parent = firstRoot;
            }
            else
            {
                firstRoot->parent = lastRoot;
            }
        }
    }
};


class Solution 
{
public:
    vector<string> trulyMostPopular(const vector<string>& names, const vector<string>& synonyms) 
    {
        UnionSet synonymSet;
        // 合并集合
        for (auto& synonym : synonyms)
        {
            int splitIndex = synonym.find(",");
            string firstName = synonym.substr(1, splitIndex - 1);
            string lastName = synonym.substr(splitIndex + 1, synonym.length() - splitIndex - 2);

            synonymSet.Insert(firstName);
            synonymSet.Insert(lastName);
            synonymSet.Union(firstName, lastName);
        }

        // 统计
        unordered_map<string, int> statics;
        for (auto& name : names)
        {
            int splitIndex = name.find("(");
            string n = synonymSet.findRoot(name.substr(0, splitIndex));
            int count = atoi(name.substr(splitIndex + 1, name.length() - splitIndex - 2).c_str());

            auto it = statics.find(n);
            if (it != statics.end())
            {
                it->second += count;
            }
            else
            {
                statics.emplace(n, count);
            }
        }
        
        // 转为指定格式
        vector<string> res;
        for (auto name : statics)
        {
            res.push_back(std::format("{}({})", name.first, name.second));
        }

        return res;
    }
};
