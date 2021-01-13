// Link To Problem:-
// https://leetcode.com/problems/decode-xored-array/

// Solution:-

class Solution
{
public:
    vector<int> decode(vector<int> &encode, int first)
    {
        vector<int> res;
        res.push_back(first);

        int n = encode.size();

        for (int i = 0; i < n; i++)
            res.push_back(encode[i] ^ res[i]);

        return res;
    }
};