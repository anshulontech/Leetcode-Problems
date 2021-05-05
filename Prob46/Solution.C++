// Link To Prolem:-
// https://leetcode.com/problems/permutations/

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