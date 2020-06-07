// https://leetcode.com/problems/coin-change-2/

// Time Complexity:-O(A*C).
// Space Complexity:-O(A*C).
    
// Approach:-
//     In this we are using a dp table in which what we are going to do is that we are going to store the number of 
// coins for sub problem. Now if we are at any poiaition than we have two possibilities with us that we will use 
// current coin or not. So we have to add the answer for both the problems and than we will get our desired result. 
// SO to get the answer we are going to do as follows , if we are not using coin than we will just get the value from 
// the top as it represents the current situation or of we are using the current coin than we will coins[i] steps back 
// in the row and add 1 to that and than add both tyhe answers to get the answer of current sub problem , So by doing 
// this we will get answer of the given problem.

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;
        int N = coins.size();
        vector<vector<int>> store(N + 1, vector<int>(amount + 1));

        for (int i = 1; i <= N; i++)
            store[i][0] = 1;

        for (int i = 1; i < N + 1; i++)
        {
            int j = 1;

            while (j < coins[i - 1] && j < amount + 1)
                store[i][j] = store[i - 1][j], j++;

            for (; j < amount + 1; j++)
                store[i][j] = store[i - 1][j] + store[i][j - coins[i - 1]];
        }

        return store[N][amount];
    }
};

// Time Complexity:-O(A*C).
// Space Complexity:-O(A).

// Approach:-
//     In this what we are doing is that we are using only 1-D array and the concept is same as that of above. Now 
// the modification is that for amount less than coin we were going to copy from the top but here there is no need to 
// do so as we will start from the coin amount hence we are already eleminating these cases.

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> store(amount + 1, 0);
        store[0] = 1;

        for (int c : coins)
        {
            for (int j = c; j < amount + 1; j++)
                store[j] += store[j - c];
        }

        return store[amount];
    }
};