// Solution:-

class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> arr(26, 0);
            for (int j = i; j < n; j++)
            {
                arr[s[j] - 'a']++;

                int min_val = INT_MAX, max_val = INT_MIN;

                for (int k = 0; k < 26; k++)
                {
                    if (arr[k] != 0)
                        min_val = min(min_val, arr[k]);

                    max_val = max(max_val, arr[k]);
                }

                res += (max_val - min_val);
            }
        }

        return res;
    }
};