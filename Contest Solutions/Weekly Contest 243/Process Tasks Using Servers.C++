// Solution.:-

class Solution
{
public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        int n = servers.size(), m = tasks.size();
        vector<int> res;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free, busy;
        int timer = 0;

        for (int i = 0; i < n; i++)
            free.push({servers[i], i});

        queue<int> q;
        for (int i = 0; i < m; i++)
            q.push(i);

        while (!q.empty())
        {
            while (!busy.empty() && busy.top().first <= timer)
            {
                auto temp = busy.top();
                busy.pop();
                free.push({servers[temp.second], temp.second});
            }

            while (!free.empty() && !q.empty() && q.front() <= timer)
            {
                int i = q.front();
                q.pop();
                auto temp = free.top();
                free.pop();
                busy.push({timer + tasks[i], temp.second});
                res.push_back(temp.second);
            }

            if (free.empty())
            {
                timer = busy.top().first;
            }
            else
                timer++;
        }

        return res;
    }
};