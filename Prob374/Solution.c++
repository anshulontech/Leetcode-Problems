// Link To Problem:-
// https://leetcode.com/problems/guess-number-higher-or-lower/description/

// Time Complexity:-O(log(N)).
// Space Complexity:-O(1).

// Approach:-
//     We will use binary search for the number in range 0 to n and on finding the number we will return that one.

class Solution
{
public:
    int guessNumber(int n)
    {
        int start = 0, end = n;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (guess(mid) == 0)
                return mid;
            else if (guess(mid) == 1)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return -1;
    }
};