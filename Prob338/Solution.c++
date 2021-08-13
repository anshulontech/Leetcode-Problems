// Link To Problem:-
// https://leetcode.com/problems/counting-bits/

// METHOD 1:-

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> store(num + 1);
        int offset = 1;
        for (int i = 1; i <= num; i++)
        {
            if (offset * 2 == i)
                offset *= 2;

            store[i] = store[i - offset] + 1;
        }

        return store;
    }
};