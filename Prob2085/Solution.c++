// Link To Probelm:-
// https://leetcode.com/problems/count-common-words-with-one-occurrence/

// Solution:-

class Solution
{
public:
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        unordered_map<string, int> first, second;

        for (auto x : words1)
            first[x]++;
        for (auto x : words2)
            second[x]++;

        int res = 0;

        for (auto x : first)
            if (x.second == 1 && second[x.first] == 1)
                res++;

        return res;
    }
};