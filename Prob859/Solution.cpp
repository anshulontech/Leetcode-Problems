// Approach 1:-

class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        if (A.size() != B.size())
            return false;
        vector<int> index;
        bool isDuplicate = false;
        unordered_map<char, int> store;
        int n = A.size();
        for (int i = 0; i < n; i++)
            if (A[i] != B[i])
                index.push_back(i);
            else
            {
                store[A[i]]++;
                if (store[A[i]] > 1)
                    isDuplicate = true;
            }

        if (index.size() != 2)
        {
            if (index.size() == 0 && isDuplicate)
                return true;
            else
                return false;
        }

        if (A[index[0]] == B[index[1]] && A[index[1]] == B[index[0]])
            return true;
        else
            return false;
    }
};