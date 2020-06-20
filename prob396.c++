// https://leetcode.com/problems/rotate-function/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     On observing the pattern the for left rotated array the sum of current elements in poisition can be obtained 
// from the previous set using the expression that first we will substract the sum of all elements from the previous 
// sum and than add the size time the 0th index element of previous order. Hence by doing this we can get the sum and 
// hence can find the max sum.

class Solution
{
public:
    int maxRotateFunction(vector<int> &A)
    {
        long total_sum = 0;
        long curr_sum = 0;

        for (int i = 0; i < A.size(); i++)
        {
            total_sum += A[i];
            curr_sum += (A[i] * i);
        }

        long max_sum = curr_sum;

        for (int i = 1; i < A.size(); i++)
        {
            curr_sum = (curr_sum - total_sum + A[i - 1] * (A.size()));
            max_sum = max(max_sum, curr_sum);
        }

        return max_sum;
    }
};