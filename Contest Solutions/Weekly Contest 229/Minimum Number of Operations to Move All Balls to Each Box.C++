// Solution:-

class Solution
{
public:
    vector<int> minOperations(string s)
    {
        int n = s.size();

        vector<int> left(n + 1, 0), right(n + 1, 0), res(n);
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            left[i + 1] = left[i] + (s[i] == '1') + sum;
            sum += (s[i] == '1');
        }

        sum = 0;

        for (int j = n - 1; j >= 0; j--)
        {
            right[j] = right[j + 1] + (s[j] == '1') + sum;
            sum += (s[j] == '1');
        }

        for (int i = 0; i < n; i++)
            res[i] = left[i] + right[i + 1];

        return res;
    }
};