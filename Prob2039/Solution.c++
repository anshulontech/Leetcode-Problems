// Link To Problem:-
// https://leetcode.com/problems/the-time-when-the-network-becomes-idle/

// Solution:-

class node
{
public:
    int val;
    vector<node *> child;
    int dist;
};

class Solution
{
private:
    node *root = new node();

    void buildGraph(vector<vector<int>> &edges, unordered_map<int, node *> &map)
    {
        for (auto x : edges)
        {
            node *first, *second;

            if (map.find(x[0]) != map.end())
                first = map[x[0]];
            else
            {
                first = new node();
                first->val = x[0];
                map[x[0]] = first;
            }

            if (map.find(x[1]) != map.end())
                second = map[x[1]];
            else
            {
                second = new node();
                second->val = x[1];
                map[x[1]] = second;
            }

            first->child.push_back(second);
            second->child.push_back(first);
        }

        return;
    }

    void findDist()
    {
        queue<node *> q;
        unordered_set<int> visited;
        int d = 0;

        q.push(root);
        visited.insert(0);

        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                node *temp = q.front();
                q.pop();

                temp->dist = d;
                for (auto x : temp->child)
                {
                    if (visited.find(x->val) == visited.end())
                    {
                        visited.insert(x->val);
                        q.push(x);
                    }
                }
            }

            d++;
        }

        return;
    }

public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience)
    {
        root->val = 0;
        unordered_map<int, node *> map;
        map.insert({0, root});

        buildGraph(edges, map);

        findDist();

        int res = 0, n = patience.size();

        for (int i = 1; i < n; i++)
        {
            int time = map[i]->dist;
            time *= 2;
            int pat = patience[i];

            int t1 = time / pat;
            if (time % pat == 0)
                t1--;

            int tempRes = time + t1 * pat;

            res = max(tempRes, res);
        }

        return res + 1;
    }
};