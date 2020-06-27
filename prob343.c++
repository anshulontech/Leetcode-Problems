// https://leetcode.com/problems/integer-break/description/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).
    
// Approach:-
//     In this approach what we are going to do is that we will make a dp vector of size n+1 which stores the max 
// product for number i at index i. So let we are standing at index i than we will look backward for all the combinations 
// that 1,i-1, or 2,i-2 or 3,i-3 and so which will give us max product . Now letf we are seeing k and i-k than i-k can be 
// split so to for this we ware using dp vector and the value at i-k index of dp vector give us the max product that 
// can be formed similarely doing in last we can obtain the answer by just looking at the last index of the dp vector.

class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;

        int i = 3;

        while (i < n + 1)
        {
            for (int j = 1; j <= i; j++)
                dp[i] = max(j * (i - j), max(j * dp[i - j], dp[i]));

            i++;
        }

        return dp[n];
    }
};