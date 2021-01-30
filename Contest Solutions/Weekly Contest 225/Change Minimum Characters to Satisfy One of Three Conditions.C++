// Solution:-

class Solution
{
public:
    int minCharacters(string a, string b)
    {
        vector<int> A(26, 0), B(26, 0);

        for (auto x : a)
            A[x - 'a']++;
        for (auto x : b)
            B[x - 'a']++;

        int first = min(count(a, b), count(b, a));

        int second = fun(A, a.size()) + fun(B, b.size());

        return min(first, second);
    }

private:
    int fun(vector<int> &A, int n)
    {
        int count = 0;

        for (int i = 0; i < 26; i++)
            count = max(count, A[i]);

        return n - count;
    }

    int count(string &a, string &b)
    {
        int res = INT_MAX;

        for (char c = 'a'; c < 'z'; c++)
        {
            int temp = 0;

            for (auto x : a)
                temp += (x > c);
            for (auto x : b)
                temp += (x <= c);

            res = min(res, temp);
        }

        return res;
    }
};