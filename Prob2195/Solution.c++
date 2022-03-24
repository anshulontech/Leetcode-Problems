// Link To The Problem:-
// https://leetcode.com/problems/append-k-integers-with-minimal-sum/

// Solution:-

class Solution
{
public:
    long long minimalKSum(vector<int> &nums, long long k)
    {
        long long sum = 0;
        nums.push_back(0);

        sort(nums.begin(), nums.end());

        int n = nums.size();
        // cout<<n<<endl;
        // cout<<nums[1]<<endl;
        // cout<<nums[n-1]<<endl;

        for (int i = 1; i < n && k > 0; i++)
        {
            if (nums[i] == nums[i - 1])
                continue;
            long long diff = nums[i] - nums[i - 1] - 1;

            if (k < diff)
                diff = k;
            sum += (diff * (diff + 1)) / 2 + ((long long)nums[i - 1]) * diff;
            k -= diff;
        }

        if (k > 0)
        {
            // cout<<"A"<<endl;
            sum += (k * (k + 1)) / 2 + ((long long)nums[n - 1]) * k;
        }

        return sum;
    }
};