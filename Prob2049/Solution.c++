// Link To Problem:-
// https://leetcode.com/problems/count-nodes-with-the-highest-score/

// Solution:-

class tree
{
public:
    int val;
    tree *leftNode, *rightNode;
    int leftCount = 0, rightCount = 0;

    tree(int t)
    {
        val = t;
        leftNode = NULL, rightNode = NULL;
        leftCount = 0, rightCount = 0;
    }
};

class Solution
{
private:
    tree *node = new tree(0);
    unsigned long long maxScore = 0, res = 0;

    void buildTree(vector<int> &parents)
    {
        unordered_map<int, tree *> map;
        map.insert({0, node});

        int n = parents.size();

        for (int i = 1; i < n; i++)
        {
            tree *parentNode = NULL, *childNode = NULL;

            if (map.find(parents[i]) == map.end())
            {
                parentNode = new tree(parents[i]);
                map.insert({parents[i], parentNode});
            }
            else
                parentNode = map[parents[i]];

            if (map.find(i) == map.end())
            {
                childNode = new tree(i);
                map.insert({i, childNode});
            }
            else
                childNode = map[i];

            if (parentNode->leftNode == NULL)
                parentNode->leftNode = childNode;
            else
                parentNode->rightNode = childNode;
        }
    }

    int dfs(tree *root)
    {
        if (root == NULL)
            return 0;

        root->leftCount = dfs(root->leftNode);
        root->rightCount = dfs(root->rightNode);

        return root->leftCount + root->rightCount + 1;
    }

    void secondDfs(tree *root, int c)
    {
        if (root == NULL)
            return;

        unsigned long long first, second, third;

        first = max(1, root->leftCount);
        second = max(1, root->rightCount);
        third = max(1, c - (root->leftCount + root->rightCount + 1));

        unsigned long long tempRes = first * second * third;

        if (maxScore < tempRes)
        {
            maxScore = tempRes;
            res = 0;
        }

        if (maxScore == tempRes)
            res++;

        secondDfs(root->leftNode, c);
        secondDfs(root->rightNode, c);

        return;
    }

public:
    int countHighestScoreNodes(vector<int> &parents)
    {
        buildTree(parents);

        dfs(node);

        int totalNode = parents.size();

        secondDfs(node, totalNode);

        return res;
    }
};