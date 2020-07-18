#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Approach 1:-  (Time Limit Exceed).

class Solution
{
public:
    bool canWinNim(int n)
    {
        if (n == 0)
            return false;

        if (n < 4)
            return true;

        vector<bool> dp(n);

        dp[0] = true;
        dp[1] = true;
        dp[2] = true;

        for (int i = 3; i < n; i++)
            dp[i] = !(dp[i - 1] && dp[i - 2] && dp[i - 3]);

        return dp[n - 1];
    }
};

// Approach 2 :-  (Math Approach).

class Solution
{
public:
    bool canWinNim(int n)
    {
        return !(n % 4 == 0);
    }
};

// Main Function

int main()
{
    cout << "Enter Number fo Stones:-" << endl;
    int n;
    cin >> n;

    Solution result;

    bool ans = result.canWinNim(n);

    if (ans)
        cout << "You can win the game if you will play smartly.";
    else
        cout << "You can not win the game in any condition.";

    return 0;
}