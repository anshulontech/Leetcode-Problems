// Link To Problem:-
// https://leetcode.com/problems/count-vowel-substrings-of-a-string/

// Solution:-

class Solution
{
public:
    int countVowelSubstrings(string word)
    {
        int res = 0, n = word.size();

        for (int i = 0; i < n; i++)
            for (int j = i + 4; j < n; j++)
            {
                string temp = word.substr(i, j - i + 1);
                if (count(temp))
                    res++;
            }

        return res;
    }

    int count(string &s)
    {
        unordered_map<char, int> map;
        map.insert({'a', 0});
        map.insert({'e', 0});
        map.insert({'o', 0});
        map.insert({'u', 0});
        map.insert({'i', 0});

        for (auto x : s)
            map[x]++;

        if (map.size() != 5)
            return false;

        for (auto x : map)
            if (x.second == 0)
                return false;

        return true;
    }
};