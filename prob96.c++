// https://leetcode.com/problems/unique-binary-search-trees/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).
    
// Approach:-
//     Here we are using dp to solve the problem as in this we going to divide the problem into subproblems such that 
// we are first calculating first for n=2 than for 3 and than for 4 and so on till we will not reach at n. Now let say 
// we are checking for k than what we will do is that we will run a inner loop to obtain the sol which works like 
// that first it will calculate the result on making 1 as root node than in that situation the answer is how we can 
// make a unique BST from k-1 nodes and we can generate the result from the dp array. next it ill check for 2 as root 
// node in this case left subtree will form from 1 node and right subtree will form from n-2 node hence we can generate 
// their values from dp array and using combination and get the desired output and so on we reach to make i as root than 
// in this case i-1 nodes are in left and n-i in right so we can find the result using combination and dp from there. 
// In the last the nth index the dp array stores the result that how many unique BST can be formed from this one and 
// hence we can return the result from there.

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> sol(n + 1, 0);
        sol[0] = 1, sol[1] = 1;

        for (int i = 2; i <= n; i++)
            for (int j = 0; j < i; j++)
                sol[i] += sol[j] * sol[i - j - 1];

        return sol[n];
    }
};