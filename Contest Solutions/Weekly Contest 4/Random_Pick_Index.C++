// Solution:-

class Solution
{
private:
    vector<int> arr;
    int n;

public:
    Solution(vector<int> &nums)
    {
        arr = nums;
        n = arr.size();
    }

    int pick(int target)
    {
        int idx = rand();

        while (arr[(idx % n)] != target)
            idx = rand();

        return idx % n;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */