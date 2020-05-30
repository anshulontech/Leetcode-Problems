// https://leetcode.com/problems/permutations/

// Time Complexity : -O(N !).
// Space Complxeity : -O(N !).To store result else we need only O(N) extra space.

// Approach:-
//     In this what we are going to do is that initially we will store all the integers in a map and than we use backtrack
// function to for help.In this function we will start to traverse the map from initial and if found any integer having
// count not equal to zero than we will add that to our tem vector else go for next one.After adding to temp we will 
// first decrease it's count and than again call for the backtrack fnction. At pint when all count;'s become zero or temp
// size will become equal to N than we will add that vector to res and goes back . and so on. 

class Solution
{
private:
    vector<vector<int>> res;
    unordered_map<int, int> store;
    int N;

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        N = nums.size();

        for (int i = 0; i < nums.size(); i++)
            store[nums[i]]++;

        unordered_map<int, int>::iterator itr = store.begin();

        for (; itr != store.end(); itr++)
        {
            int help = itr->first;
            store[help]--;
            vector<int> temp;
            temp.push_back(help);
            backtrack(temp);
            store[help]++;
        }

        return res;
    }

    void backtrack(vector<int> &temp)
    {
        if (temp.size() == N)
        {
            res.push_back(temp);
            return;
        }
        unordered_map<int, int>::iterator itr = store.begin();
        for (; itr != store.end(); itr++)
            if (store[itr->first] == 0)
                continue;
            else
            {
                int help = itr->first;
                store[help]--;
                temp.push_back(help);
                backtrack(temp);
                temp.pop_back();
                store[help]++;
            }
    }
};