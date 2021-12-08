// Link To Problem:-
// https://leetcode.com/problems/finding-3-digit-even-numbers/

// Solution:-

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        unordered_set<int> visited;
        vector<int> res;
        int n = digits.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (i != j && j != k && k != i)
                    {
                        helper(digits[i], digits[j], digits[k], res, visited);
                    }

        sort(res.begin(), res.end());
        return res;
    }

    void helper(int a, int b, int c, vector<int> &res, unordered_set<int> &visited)
    {
        if (a == 0 || c % 2 != 0)
            return;

        int num = a * 100 + b * 10 + c;

        if (visited.find(num) != visited.end())
            return;

        res.push_back(num);
        visited.insert(num);
    }
};