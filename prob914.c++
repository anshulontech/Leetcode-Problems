// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     Initially we will store the count of each number in a map, and than we will find the greatest common divisor(gcd) 
// for the count of the numbers. In this gcd reprsents the max value of X in this problem. So if the value of gcd is 
// greater than 1 than we will return true else return false.

class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> store;

        for (int i = 0; i < deck.size(); i++)
            store[deck[i]]++;

        int gcd = 0;

        for (auto x : store)
            gcd = gcD(gcd, x.second);

        return gcd > 1;
    }

    int gcD(int a, int b)
    {
        if (a == 0)
            return b;

        return gcD(b % a, a);
    }
};