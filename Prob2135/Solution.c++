// Link To Problem:-
// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/

// Solution 01:-

class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        unordered_set<string> set;

        for (auto &x : startWords)
        {
            sort(x.begin(), x.end());
            set.insert(x);
        }

        int res = 0;

        for (auto x : targetWords)
        {
            int n = x.size();
            for (int i = 0; i < n; i++)
            {
                string temp = "";

                temp += x.substr(0, i) + x.substr(i + 1, n - i - 1);
                sort(temp.begin(), temp.end());

                if (set.find(temp) != set.end())
                {
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};

// Solution 02:-

class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        unordered_set<int> visited;
        for (auto s : startWords)
        {
            int hash = 0;

            for (auto x : s)
                hash += (1 << (x - 'a'));

            visited.insert(hash);
        }

        int res = 0;

        for (auto s : targetWords)
        {
            int n = s.size();

            for (int i = 0; i < n; i++)
            {
                int hash = 0;

                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                        continue;

                    hash += (1 << (s[j] - 'a'));
                }

                if (visited.find(hash) != visited.end())
                {
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};