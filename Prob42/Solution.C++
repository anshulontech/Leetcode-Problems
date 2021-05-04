// Link To Problem:-
// https://leetcode.com/problems/trapping-rain-water/

int findnextlarge(vector<int> &, int);
int findnextlarge2(vector<int> &, int);

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() == 0)
            return 0;
        int water = 0;
        int i = 0;
        while (i < height.size() && height[i] == 0)
            i++;
        for (; i < height.size() - 1; i++)
        {
            int index = findnextlarge(height, i);
            int sum = 0;
            if (index != NULL)
            {
                int j;
                for (j = i + 1; j < index; j++)
                    sum += height[j];

                water += (index - i - 1) * height[i] - sum;
                i = index - 1;
            }
            else
            {
                index = findnextlarge2(height, i + 1);
                if (index == NULL)
                    continue;
                else
                {
                    int j;
                    for (j = i + 1; j < index; j++)
                        sum += height[j];

                    water += (index - i - 1) * min(height[index], height[i]) - sum;
                    i = index - 1;
                }
            }
        }
        return water;
    }
};

int findnextlarge(vector<int> &height, int start)
{
    for (int i = start + 1; i < height.size(); i++)
        if (height[start] <= height[i])
            return i;
    return NULL;
}
int findnextlarge2(vector<int> &height, int start)
{
    int maxi = height[start];
    int index = NULL;
    for (int i = start + 1; i < height.size(); i++)
        if (height[i] >= maxi)
        {
            index = i;
            maxi = height[i];
        }
    return index;
}