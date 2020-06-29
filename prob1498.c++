// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(N).
    
// Approach:-
//     Initially we make a power array which will tell us that how many combinations can be formed if we are standing 
// at i and j index than the possible number of combinations are pows[j-i] or i-j whatever it is depanding on what is 
// bigger. Now we will first sort the given array and than find the max window in it such that min val is nums[0] and 
// max value satisfy the condition of target. After this using pows array we will generate how many combinations can 
// be formed and than reduce our window by increasing starting pointer and than find the window for which condition 
// is true in consideration with the thing that min element is now nums[1] and so we will follow the procedure till 
// the start becomes greater than end .

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size(), start = 0, end = n - 1, res = 0, mod = 1e9 + 7;
        vector<int> pows(n);
        pows[0] = 1;
        for (int i = 1; i < n; i++)
            pows[i] = (pows[i - 1] * 2) % mod;

        while (start <= end)
            if (nums[start] + nums[end] > target)
                end--;
            else
                res = (res + pows[end - start++]) % mod;

        return res;
    }
};