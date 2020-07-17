#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_map>

using namespace std;

// Approach 1 : -

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                    return {i, j};

        return {};
    }
};

// Approach 2 :-

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> store;

        for (int i = 0; i < nums.size(); i++)
            if (store.find(target - nums[i]) != store.end())
                return {store[target - nums[i]], i};
            else
                store[nums[i]] = i;

        return {};
    }
};

// Main function


int main() {
    vector<int> nums={2, 7, 11, 15};
    int target=9;

    Solution result;

    vector<int> res=result.twoSum(nums,target);

    cout<<"The result is: {"<<res[0]<<","<<res[1]<<"}"<<endl;

    return 0;
}