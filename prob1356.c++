// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(N). For sorting.
    
// Approach:-
//     Using compare function we will sort the elements on the basis of number of bits.

// Compare function:-
//     We will first calculate number of bits of each number using predefined function __builtin_popcount and if the 
// number of bits are same than we return the same nuber else return the condition for number having less number of 
// bits.

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }

    static bool compare(const int &a, const int &b)
    {
        int c1 = __builtin_popcount(a);
        int c2 = __builtin_popcount(b);

        if (c1 == c2)
            return a < b;

        return c1 < c2;
    }
};