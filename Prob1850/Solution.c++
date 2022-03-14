// Link To The Problem:-
// https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/

// Solution:-

class Solution
{
public:
    int getMinSwaps(string num, int k)
    {
        string temp = num;

        for (int i = 0; i < k; i++)
            next_permutation(temp.begin(), temp.end());

        return minSteps(num, temp);
    }

    int minSteps(string &num, string &temp)
    {
        int n = num.size();

        int i = 0, j = 0, res = 0;

        while (i < n)
        {
            j = i;

            while (num[i] != temp[j])
                j++;

            while (i < j)
            {
                swap(temp[j], temp[j - 1]);
                j--;
                res++;
            }
            i++;
        }

        return res;
    }
};