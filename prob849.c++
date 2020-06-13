// https://leetcode.com/problems/maximize-distance-to-closest-person/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are going to do is that we will check max dist between any two 1 and also between 1st one from 
// 0th index and last one from end and than return the maximum distance which would form. Now for dist for middle elements 
// we are taking (dist+1)/2 because of the reason that we are inseting the element in the mid that's we want the dist from 
// middle.

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int N = seats.size();
        int i = 0;

        while (i < N && seats[i] == 0)
            i++;

        int max_dist = i;

        int dist = 0;
        while (i < N)
        {
            if (seats[i] == 1)
            {
                max_dist = max(max_dist, (dist + 1) / 2);
                dist = 0;
            }
            else
                dist++;

            i++;
        }

        max_dist = max(max_dist, dist);

        return max_dist;
    }
};