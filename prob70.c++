// https://leetcode.com/problems/climbing-stairs/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this we are using a dp array named store which stores that the maximum number of steps to reach at that 
// point. Now let us assume that you are at ith index than to calculate the maximum number of steps what you should 
// do is to first check for i-1 as top and than for i-2 as top and than add them to obtain the answer so here we are 
// doing the same we will add the number of steps to reach i-1 as top and than number of steps to reach i-2 as top 
// and store them for ith index. At last we are all done with the array and hence we cab return the value stored at 
// nth index.
    
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 2)
            return 1;
        vector<int> store(n + 1);

        store[0] = 1;
        store[1] = 1;

        for (int i = 2; i < n + 1; i++)
            store[i] = store[i - 1] + store[i - 2];

        return store[n];
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
//     Similar Approach but here we are using array to store the values insetead we are storing them into first_last 
// and second_last variable as we need only them to solve the curr poisition. 

class Solution
{
public:
    int climbStairs(int n)
    {
        int first_last = 1, second_last = 1;

        for (int i = 2; i < n + 1; i++)
        {
            int temp = first_last + second_last;
            second_last = first_last;
            first_last = temp;
        }

        return first_last;
    }
};