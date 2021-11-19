// Link To Problem:-
// https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/

// Solution:-

class Solution
{
public:
    bool checkAlmostEquivalent(string word1, string word2)
    {
        vector<int> arr(26, 0);
        for (auto x : word1)
            arr[x - 'a']++;
        for (auto x : word2)
            arr[x - 'a']--;

        for (auto x : arr)
            if (abs(x) > 3)
                return false;

        return true;
    }
};