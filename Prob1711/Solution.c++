// Link To Problem:-
// https://leetcode.com/problems/count-good-meals/

// Solution:-

class Solution
{
public:
    int countPairs(vector<int> &A)
    {
        unordered_map<int, int> store;
        int res = 0, mod = pow(10, 9) + 7;

        for (auto x : A)
        {
            int power = 1;

            for (int i = 1; i <= 22; i++)
            {
                if (store.find(power - x) != store.end())
                {
                    res += store[power - x];
                    res %= mod;
                }
                power *= 2;
            }

            store[x]++;
        }

        return res;
    }
};