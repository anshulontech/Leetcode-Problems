#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// Approach 1:-

class TrieNode
{
public:
    vector<TrieNode *> children;
    int val;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            children.push_back(nullptr);

        val = 0;
    }
};

class MapSum
{
private:
    TrieNode *root = new TrieNode();
    unordered_map<string, int> store;

public:
    MapSum()
    {
    }

    void insert(string key, int value)
    {
        int val = store[key];
        store[key] = value;

        TrieNode *temp = root;

        for (auto c : key)
            if (temp->children[c - 'a'] != NULL)
            {
                temp = temp->children[c - 'a'];
                temp->val = temp->val - val + value;
            }
            else
            {
                temp->children[c - 'a'] = new TrieNode();
                temp = temp->children[c - 'a'];
                temp->val = temp->val - val + value;
            }
    }

    int sum(string prefix)
    {
        TrieNode *temp = root;
        for (auto c : prefix)
        {
            if (!temp)
                break;
            temp = temp->children[c - 'a'];
        }

        return temp ? temp->val : 0;
    }
};

// Main Function

int main()
{
    MapSum result;

    result.insert("apple", 3);
    int ans = result.sum("app");
    cout << ans << endl;

    result.insert("app", 5);
    ans = result.sum("ap");
    cout << ans << endl;

    result.insert("apple", 10);
    ans = result.sum("app");
    cout << ans << endl;

    return 0;
}