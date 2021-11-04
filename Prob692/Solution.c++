// Link To Problem:-
// https://leetcode.com/problems/top-k-frequent-words/submissions/

// METHOD 1:-

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> store;

        for (auto &w : words)
            ++store[w];

        vector<vector<string>> bucket(words.size());

        for (auto it : store)
            bucket[it.second].push_back(it.first);

        vector<string> res;

        for (int i = (int)bucket.size() - 1; k > 0 && i >= 0; i--)
        {
            if (bucket[i].empty())
                continue;

            int n = min(k, (int)bucket[i].size());
            res.insert(res.end(), bucket[i].begin(), bucket[i].begin() + n);
            k -= n;
        }

        return res;
    }
};