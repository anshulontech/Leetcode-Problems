// Solution:-

class Solution
{
public:
    int getNumberOfBacklogOrders(vector<vector<int>> &orders)
    {
        priority_queue<vector<int>> backlog;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> sell;

        for (auto &x : orders)
            if (x[2] == 0)
            {
                if (sell.empty() || sell.top()[0] > x[0])
                    backlog.push({x[0], x[1]});
                else
                {
                    while (x[1] > 0 && !(sell.empty() || sell.top()[0] > x[0]))
                    {
                        vector<int> temp = sell.top();
                        sell.pop();

                        int count = min(x[1], temp[1]);
                        x[1] -= count;
                        temp[1] -= count;

                        if (temp[1] != 0)
                            sell.push({temp[0], temp[1]});
                    }

                    if (x[1] > 0)
                        backlog.push({x[0], x[1]});
                }
            }
            else
            {
                if (backlog.empty() || (backlog.top()[0] < x[0]))
                    sell.push({x[0], x[1]});
                else
                {
                    while (x[1] > 0 && !(backlog.empty() || (backlog.top()[0] < x[0])))
                    {
                        vector<int> temp = backlog.top();
                        backlog.pop();

                        int count = min(x[1], temp[1]);
                        x[1] -= count;
                        temp[1] -= count;

                        if (temp[1] != 0)
                            backlog.push({temp[0], temp[1]});
                    }

                    if (x[1] > 0)
                        sell.push({x[0], x[1]});
                }
            }

        int count = 0, mod = 1e9 + 7;

        while (!backlog.empty())
        {
            count = (count + backlog.top()[1]) % mod;
            backlog.pop();
        }

        while (!sell.empty())
        {
            count = (count + sell.top()[1]) % mod;
            sell.pop();
        }

        return count % mod;
    }
};