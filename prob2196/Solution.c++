// Link To The Problem:-
// https://leetcode.com/problems/create-binary-tree-from-descriptions/

// Solution:-

class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        map<int, TreeNode *> map;
        set<int> isChild;

        for (auto &x : descriptions)
        {
            TreeNode *par = NULL, *child = NULL;

            if (map.find(x[0]) == map.end())
            {
                par = new TreeNode(x[0]);
                map[x[0]] = par;
            }
            else
                par = map[x[0]];

            if (map.find(x[1]) == map.end())
            {
                child = new TreeNode(x[1]);
                map[x[1]] = child;
            }
            else
                child = map[x[1]];

            isChild.insert(x[1]);

            if (x[2])
                par->left = child;
            else
                par->right = child;
        }

        TreeNode *res = NULL;

        for (auto &x : map)
            if (isChild.find(x.first) == isChild.end())
            {
                res = x.second;
                break;
            }

        return res;
    }
};