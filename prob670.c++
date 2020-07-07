// https://leetcode.com/problems/maximum-swap/description/

// Time Complexity:-O(N^2).
// Space Complexity:-O(1).
    
// Aproach:-
//     In this wwhat we are going to do is that we will start to traverse the num in string from 0th index and if found 
// at any index value than 0 index than we will swap these two and than return the number if it is not than we will 
// check for the ndex 1 and son on.

class Solution
{
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);

        for (int i = 0; i < s.size(); i++)
        {
            int index = Max_val(s, i);
            if (s[i] != s[index])
            {
                swap(s[i], s[index]);
                break;
            }
        }

        return stoi(s);
    }

    int Max_val(string &s, int index)
    {
        int res = index;

        for (int i = index + 1; i < s.size(); i++)
            if (s[i] >= s[res])
                res = i;

        return res;
    }
};
// Time Complexity:-O(N).
// Space Complexity:-O(1).

class Solution
{
public:
    int maximumSwap(int num)
    {
        string res = to_string(num);

        int maxNum = -1, maxIdx = -1;
        int leftIdx = -1, rightIdx = -1;

        for (int i = res.size() - 1; i >= 0; i--)
        {
            if (res[i] > maxNum)
            {
                maxNum = res[i];
                maxIdx = i;
                continue;
            }

            if (res[i] < maxNum)
            {
                leftIdx = i;
                rightIdx = maxIdx;
            }
        }

        if (leftIdx == -1)
            return num;

        swap(res[leftIdx], res[rightIdx]);

        return stoi(res);
    }
};