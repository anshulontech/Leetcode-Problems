// https://leetcode.com/problems/can-place-flowers/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are going to do is that for each 0 slot we will check that is a new flower can be planted their 
// or not, if it was than we increase our count else move for nect slot. The loop will run till we will not reach the 
// end of array or the count would not become equal to n .

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int N = flowerbed.size();
        int count = 0;
        int i = 0;
        while (i < N)
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == N - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i++] = 1;
                count++;
            }
            if (count >= n)
                return true;

            i++;
        }

        return false;
    }
};