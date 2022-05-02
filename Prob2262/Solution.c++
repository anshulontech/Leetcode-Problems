// Link To The Problem:-
// https://leetcode.com/problems/total-appeal-of-a-string/

// Solution 1:-

class Solution
{
public:
    long long appealSum(string s)
    {
        vector<int> lastIdx(26, -1);
        int n = s.size();

        long long res = 0;

        for (int i = 0; i < n; i++)
        {
            lastIdx[s[i] - 'a'] = i;
            for (int j = 0; j < 26; j++)
                if (lastIdx[j] == -1)
                    continue;
                else
                {
                    res += (lastIdx[j] + 1);
                }
        }

        return res;
    }
};

// Solution 2:-

class Solution
{
public:
    long long appealSum(string s)
    {
        vector<int> lastIdx(26, 0);
        int n = s.size();

        long long res = 0;

        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += i + 1 - lastIdx[s[i] - 'a'];
            lastIdx[s[i] - 'a'] = i + 1;
            res += sum;
        }

        return res;
    }
};