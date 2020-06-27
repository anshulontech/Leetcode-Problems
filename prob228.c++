// https://leetcode.com/problems/summary-ranges/

// Time Complexity : -O(N).Space Complexity : -O(N).To store the result.

// Approach :-
//     We will use two pointers in this question. Now the first pointer points to any index and from there we will run 
// another pointer till the elements in the window forms a continues pattern and the point where the loop end we will 
// insert the interval that is represented by the pointers in the that situtation. Also there are some updates such as 
// what if pointer points to end what if there is only one element in the loop or interval. So these cases are explained 
// in the code.

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {

        vector<string> res;

        for (int i = 0; i < nums.size(); i++)
        {
            int prev = i; // To represents the start of the interval.

            while (i < nums.size() - 1 && nums[i] == (nums[i + 1] - 1))
                i++; // Increase i till the continues arry id formed.

            if (i == prev)
            { // If there is ony one element in the loop.
                res.push_back({to_string(nums[i])});
            }
            else if (i == nums.size() - 1 && nums[i] == nums[i - 1])
            { // If the last element is also part of current interval than we should add that one
                string help = to_string(nums[prev]) + "->" + to_string(nums[i]);
                res.push_back(help);
            }
            else
            { // In all other cases we will add starting and end of the interval in a string.
                string help = to_string(nums[prev]) + "->" + to_string(nums[i]);
                res.push_back(help);
            }
        }

        return res;
    }
};