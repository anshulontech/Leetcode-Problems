// Solution:-

class Solution
{
public:
    vector<int> decode(vector<int> &encoded)
    {
        int xorAll = 0, n = encoded.size() + 1;
        vector<int> res(n);

        for (int i = 1; i <= n; i++)
            xorAll ^= i;

        for (int i = 0; i < n - 1; i += 2)
            xorAll ^= encoded[i];

        res[n - 1] = xorAll;

        for (int j = n - 2; j >= 0; j--)
            res[j] = res[j + 1] ^ encoded[j];

        return res;
    }
};