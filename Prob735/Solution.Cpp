// Approach 1:-

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();

        stack<int> store;

        for (int i = 0; i < n; i++)
            if (store.empty() || store.top() * asteroids[i] > 0)
                store.push(asteroids[i]);
            else
            {
                if (asteroids[i] > 0)
                    store.push(asteroids[i]);
                else
                {
                    int flag = 1;

                    while (!store.empty() && store.top() * asteroids[i] < 0)
                        if (abs(store.top()) > abs(asteroids[i]))
                        {
                            flag = 0;
                            break;
                        }
                        else if (abs(store.top()) < abs(asteroids[i]))
                            store.pop();
                        else
                        {
                            flag = 0;
                            store.pop();
                            break;
                        }

                    if (flag)
                        store.push(asteroids[i]);
                }
            }

        vector<int> res(store.size());

        while (!store.empty())
        {
            res[store.size() - 1] = store.top();
            store.pop();
        }

        return res;
    }
};