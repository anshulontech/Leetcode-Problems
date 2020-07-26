// Approach 1:-

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        int N = s.size();

        string res;

        for (int i = 0; i < N; i++)
            res += " ";

        for (int i = 0; i < N; i++)
            res[indices[i]] = s[i];

        return res;
    }
};