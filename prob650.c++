// // https://leetcode.com/problems/2-keys-keyboard/description/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).
    
// Approach:-
//     In this we are oign to use the dp vector to store the result for previous values. Now as we knoe that the 
// largest value of a number is that number itself so initially we will fill that poisition with number . Now we 
// will search for the back that first number which divides the number completely will make it minimum hence we will 
// go from there and than upadate the answer with that value + quotient.

class Solution
{
public:
    int minSteps(int n)
    {
        vector<int> dp(n + 1);

        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = i;
            for (int j = i - 1; j > 1; j--)
            {
                if (i % j == 0)
                {
                    dp[i] = dp[j] + (i / j);
                    break;
                }
            }
        }

        return dp[n];
    }
};