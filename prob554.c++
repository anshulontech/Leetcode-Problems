// https://leetcode.com/problems/brick-wall/description/

// Time Complexity:-O(M*N).
// Space Complexity:-O(N*M).
    
// Approach:-
//     Let us think that if we are moving from left to right than the set of bricks in left will form a single brick 
// of size equal to sum of the passed bricks. Now we will move from left to right in each row and we will store the 
// count of each long brik which can be formd by joining all the bricks in the left, also we here are taking a max_val 
// variable which represents the max count of any brick formed. Now on as when we pass a wall from the width equal to 
// that one represented by max val would result into the minimum number of brick to cut as the max number of bricks 
// here are touching the wall with their edge.

class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<int, int> store;
        int max_val = 0;

        for (int i = 0; i < wall.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; j++)
            {
                sum += wall[i][j];
                store[sum]++;

                max_val = max(max_val, store[sum]);
            }
        }

        return wall.size() - max_val;
    }
};