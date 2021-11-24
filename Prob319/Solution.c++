// Link To Problem:-
// https://leetcode.com/problems/bulb-switcher/description/

// Time Complexity:-O(1).
// Space Complexity:-O(1).

// Approach:-
//     As on observation the factors of number ar as follows

//     1->1        6->4        11->2       16->5.
//     2->2        7->2        12->6
//     3->2        8->4        13->2
//     4->3        9->3        14->4
//     5->2        10->4       15->4

//     So observation it is found that the odd number fo factors are found only at perfect square number so by doing
// the given operation only the perfect square number present before n will remain on . So to do this we will just
// calculate the square root of n which give us that how many prefect square are present before n .

class Solution
{
public:
    int bulbSwitch(int n)
    {
        return sqrt(n);
    }
};