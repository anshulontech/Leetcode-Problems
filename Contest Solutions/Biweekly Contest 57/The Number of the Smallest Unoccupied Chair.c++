// Solution:-

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        vector<vector<int>> arr;
        int n = times.size();

        for (int i = 0; i < n; i++)
            arr.push_back({times[i][0], times[i][1], i});

        sort(arr.begin(), arr.end());

        // for(auto x:arr)
        //     cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;

        priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> time;

        for (int i = 0; i < n; i++)
            pq.push(i);

        for (int i = 0; i < n; i++)
        {
            while (!time.empty() && time.top().first <= arr[i][0])
            {
                pq.push(time.top().second);
                time.pop();
            }

            if (arr[i][2] == targetFriend)
                return pq.top();

            time.push({arr[i][1], pq.top()});
            pq.pop();
        }

        return -1;
    }
};