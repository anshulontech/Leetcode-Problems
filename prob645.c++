// https://leetcode.com/problems/set-mismatch/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are goig to do is that we will iterate the array and for nums[i] we will make nums[i]-1 index 
// negative representing that it occured . Now for missing number it's index s not negative and for double occured 
// nuber it's index become negative two times and hence we can say that it will become poisitiove , so by itterating 
// the array again we can find those numbers. Now we will calculate the total sum and sum of the array which will tell 
// us that if total sum is found to be less than the sum of the array elements than the smaller fo thee two number 
// obtained occured twice else the bigger number occured twice and by doing this we can return the answer in the order 
// as asked.

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            nums[abs(nums[i]) - 1] = (-1) * (nums[abs(nums[i]) - 1]);
            sum += abs(nums[i]);
        }
        int total = n * (n + 1) / 2;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                res.push_back(i + 1);

        if (total < sum)
            return swap(res);
        else
            return res;
    }

    vector<int> swap(vector<int> &res)
    {
        int temp = res[0];
        res[0] = res[1];
        res[1] = temp;

        return res;
    }
};

// Similar apparoch Without calculating sum as that if we will encounter with already -ve number than we will assign
// it as duplicate number and continue for earch and the number which is only +ve in the array is called as missing 
// number and hence we have result with us so we can return them in order as asked.

    class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int dup = -1, missing = 1;
        for (int n : nums)
        {
            if (nums[abs(n) - 1] < 0)
                dup = abs(n);
            else
                nums[abs(n) - 1] *= -1;
        }

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] > 0)
            {
                missing = i + 1;
                break;
            }

        vector<int> res;
        res.push_back(dup);
        res.push_back(missing);

        return res;
    }
};