// https://leetcode.com/problems/max-chunks-to-make-sorted/description/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int count = 0, max_val = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            max_val = max(max_val, arr[i]);

            if (max_val == i)
                count++;
        }

        return count;
    }
};