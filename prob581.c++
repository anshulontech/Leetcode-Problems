// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(N).

// Approach:-
//     In this we will store the given array and than sort that one newely formed array , now we will check from the
// start that how many elements in given array are in continues poisition from start in sorted aorder and same from
// the end , after this the trest of the elements left are not in correct poisition hence we have to sort them, so we
// will return the length of that part.

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> temp = nums;

        sort(nums.begin(), nums.end());

        int start = 0;

        while (start < nums.size() && nums[start] == temp[start])
            start++;

        int end = nums.size() - 1;

        while (end > start && nums[end] == temp[end])
            end--;

        return end - start + 1;
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(N).

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        stack<int> store;

        int N = nums.size(), r = 0, l = N;

        for (int i = 0; i < N; i++)
        {
            while (!store.empty() && nums[store.top()] > nums[i])
            {
                l = min(l, store.top());
                store.pop();
            }

            store.push(i);
        }

        while (!store.empty())
            store.pop();

        for (int i = N - 1; i >= 0; i--)
        {
            while (!store.empty() && nums[store.top()] < nums[i])
            {
                r = max(r, store.top());
                store.pop();
            }

            store.push(i);
        }

        return r - l > 0 ? r - l + 1 : 0;
    }
};