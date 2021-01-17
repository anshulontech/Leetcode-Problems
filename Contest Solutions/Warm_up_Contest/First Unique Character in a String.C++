// Solution:-

class Solution
{
public:
    int firstUniqChar(string s)
    {
        queue<pair<char, int>> q;
        vector<int> arr(26, 0);
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            arr[s[i] - 'a']++;
            if (arr[s[i] - 'a'] == 1)
            {
                q.push({s[i], i});
            }
        }

        while (!q.empty())
        {
            if (arr[q.front().first - 'a'] == 1)
                return q.front().second;
            else
                q.pop();
        }

        return -1;
    }
};