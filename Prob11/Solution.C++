// Problem Link:-
// https://leetcode.com/problems/container-with-most-water/

// Approach 1:-

class Solution
{
public:
    int maxArea(vector<int> &H)
    {
        if (H.size() == 0 || H.size() == 1)
            return 0;
        int max = INT_MIN;
        for (int i = 0; i < H.size() - 1; i++)
            for (int j = i + 1; j < H.size(); j++)
                if ((j - i) * min(H[i], H[j]) > max)
                    max = (j - i) * min(H[i], H[j]);

        return max;
    }
};

// Approach 2:-

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j)
                i++;
            while (height[j] <= h && i < j)
                j--;
        }

        return water;
    }
};