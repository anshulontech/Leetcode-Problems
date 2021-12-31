// Link To Problem:-
// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/submissions/

// Solution 1:-

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        unordered_set<string> set;

        for (auto &x : supplies)
            set.insert(x);

        vector<string> res;
        int n = recipes.size();

        while (1)
        {
            int count = 0;

            for (int i = 0; i < n; i++)
            {
                if (set.find(recipes[i]) != set.end())
                    continue;

                bool isAllPresent = true;
                for (auto x : ingredients[i])
                {
                    if (set.find(x) == set.end())
                    {
                        isAllPresent = false;
                        break;
                    }
                }

                if (isAllPresent)
                {
                    res.push_back(recipes[i]);
                    set.insert(recipes[i]);
                    count++;
                }
            }

            if (!count)
                break;
        }

        return res;
    }
};
