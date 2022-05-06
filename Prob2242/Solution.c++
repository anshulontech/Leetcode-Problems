// Link To The Problem:-
// https://leetcode.com/problems/maximum-score-of-a-node-sequence/

// Solution:-

class Node
{
public:
    int val;
    int score;
    vector<pair<int, int>> child;

    Node(int val1, int val2)
    {
        val = val1;
        score = val2;
    }
};

bool static cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first <= b.first)
        return false;
    return true;
}

class Solution
{
public:
    int maximumScore(vector<int> &scores, vector<vector<int>> &edges)
    {
        unordered_map<int, Node *> map;

        int n = scores.size();

        for (int i = 0; i < n; i++)
        {
            Node *node = new Node(i, scores[i]);
            map[i] = node;
        }

        for (auto x : edges)
        {
            Node *first = map[x[0]], *second = map[x[1]];

            first->child.push_back({scores[x[1]], x[1]});
            second->child.push_back({scores[x[0]], x[0]});
        }

        int res = -1;

        for (int i = 0; i < n; i++)
        {
            Node *node = map[i];
            sort(node->child.begin(), node->child.end(), cmp);
        }

        for (auto x : edges)
        {
            Node *first = map[x[0]], *second = map[x[1]];

            if (first->child.size() < 2 || second->child.size() < 2)
                continue;

            for (int i = 0; i < first->child.size() && i < 3; i++)
            {
                if (first->child[i].second == second->val)
                    continue;
                for (int j = 0; j < second->child.size() && j < 3; j++)
                    if (second->child[j].second == first->val || second->child[j].second == first->child[i].second)
                        continue;
                    else
                        res = max(res, first->score + second->score + first->child[i].first + second->child[j].first);
            }
        }

        return res;
    }
};