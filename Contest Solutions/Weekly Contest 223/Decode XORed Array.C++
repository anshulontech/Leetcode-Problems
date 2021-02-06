// Solution:-

class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        int n = encoded.size();

        vector<int> res;
        res.push_back(first);
        int val;

        for (int i = 0; i < n; i++)
        {
            val = encoded[i] ^ first;
            res.push_back(val);
            first = val;
        }

        return res;
    }
};