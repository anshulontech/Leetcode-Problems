// Link To Problem:-
// https://leetcode.com/problems/h-index-ii/

// Time Coplexity:-O(log(N)).
// Space Complexity:-O(1).

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int start = 0, len = citations.size(), end = len - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (citations[mid] >= (len - mid))
                end = mid - 1;
            else
                start = mid + 1;
        }

        return len - start;
    }
};