// Approach 1:-

class NumArray
{
private:
    vector<int> prefixSum;

public:
    NumArray(vector<int> &nums)
    {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            prefixSum.push_back(sum);
            sum += nums[i];
        }
        prefixSum.push_back(sum);

        return;
    }

    int sumRange(int i, int j)
    {
        return prefixSum[j + 1] - prefixSum[i];
    }
};