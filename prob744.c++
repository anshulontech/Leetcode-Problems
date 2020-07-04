// https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/

// Time Complexity:-O(log(n)).
// Space Complexity:-O(1).

// Approach:-
//     Use the concept of binary search.

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int start = 0, end = letters.size();

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (letters[mid] <= target)
                start = mid + 1;
            else
                end = mid;
        }

        return letters[start % letters.size()];
    }
};