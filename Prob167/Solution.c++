// Link To Problem:-
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int start = 0, end = numbers.size() - 1;
        while (start < end && (numbers[start] + numbers[end]) != target)
            if ((numbers[start] + numbers[end]) > target)
                end--;
            else
                start++;

        vector<int> A;
        A.push_back(start + 1);
        A.push_back(end + 1);

        return A;
    }
};