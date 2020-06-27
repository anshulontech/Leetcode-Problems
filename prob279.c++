// https://leetcode.com/problems/perfect-squares/description/

// Time Complexity:-O(N^2). 
// Space Complexity:-O(N)

// Approach:-
//     In this what we are going to do is to use dynamic programming to solve this problem . We are maintaing a dp 
// array which will tell for ith index us the minimum number of perfect squares required to form the ith number . Now 
// let us assume we are standing on any k index than from that index what we can do is that we will first check that 
// what if 1 is one of those number to make k from perfect square so in that situation we can just add 1 to what was 
// on k-1 index , now we will check for what if one of these is 4 so we will compare the min value from dp[k] and 
// dp[k-4] similarely we will go 9 , 16 , 25 and so on till the perfect square will not go beyond k. At last the 
// dp[n] rpresents the min number of perfect squares required to make the number n.
    
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i < n + 1; i++)
            for (int j = 1; i - j * j >= 0; j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);

        return dp[n];
    }
};

// Approach 2 :-
//     Here We are doing the same but in this case we are using static vector due to which what is happening is that 
// the array we formed in the last case will also remain active for the next test case and during the next test case 
// we will not start from the start but we will start from the dp.size() as the array formed in the previous we are continuing
// the array from the previous case. 

class Solution
{
public:
    int numSquares(int n)
    {
        static vector<int> dp({0});

        cout << dp.size() << endl;

        while (dp.size() <= n)
        {
            int m = dp.size();
            int val = INT_MAX;

            for (int i = 1; i * i <= m; i++)
                val = min(val, dp[m - i * i] + 1);

            dp.push_back(val);
        }

        return dp[n];
    }
};

Approch 3 :-
    Using Legendre's three-square theorem. 

class Solution
{
public:
    int numSquares(int n)
    {

        if (n <= 0)
            return 0;

        if (isSquare(n)) // If n is a perfect square, return 1.
            return 1;

        // The result is 4 if and only if n can be written in the form of 4^k*(8*m + 7). Refer to Legendre's three-square theorem.
        while (n % 4 == 0)
            n /= 4;

        if (n % 8 == 7)
            return 4;

        // Check whether 2 is the result.

        for (int i = 1; i <= sqrt(n); i++)
            if (isSquare(n - i * i))
                return 2;

        return 3;
    }

    bool isSquare(int n)
    {
        int val = sqrt(n);

        return val * val == n;
    }
};