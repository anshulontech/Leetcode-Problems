// https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/description/

// Time Complexity:-O(1).
// Space Complexity:-O(1).
    
// Approach:-
//     Using Simple Maths.
    
//     Like let we are making x Jumbo Burger and y small burger than we required 4x+2y slices of tomato and x+y slices 
// of cheese. So we ahve 2 equations 4x+2y=tomatoslices and x+y=cheeseslices , now if we will solve these equations using 
// basic maths anf if we have solution for this we will return them or if we have no solution than we will return false. 
// Basic thing to note is that x and y are non negative instegers.

class Solution
{
public:
    vector<int> numOfBurgers(int t, int c)
    {
        int first = (t - c * 2);

        if (first < 0 || first % 2 != 0)
            return {};

        int second = c - first / 2;

        if (second < 0)
            return {};
        else
            return {first / 2, second};
    }
};