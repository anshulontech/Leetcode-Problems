// Approach 1:-

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int count = 0;
        unordered_set<char> vowels;
        vowels.insert('u'), vowels.insert('o'), vowels.insert('i'), vowels.insert('e'), vowels.insert('a');

        int res = 0;
        int curr = 0;

        int start = 0, end = 0;

        while (end < k)
        {
            if (vowels.find(s[end]) != vowels.end())
                curr++;

            end++;
        }

        res = max(res, curr);

        while (end < s.size())
        {
            if (vowels.find(s[end]) != vowels.end())
                curr++;
            end++;
            if (vowels.find(s[start]) != vowels.end())
                curr--;
            start++;

            res = max(res, curr);
        }

        return res;
    }
};

// Approach 2:-

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        vector<int> vowels(26);
        vowels[0] = 1;
        vowels['e' - 'a'] = 1;
        vowels['i' - 'a'] = 1;
        vowels['o' - 'a'] = 1;
        vowels['u' - 'a'] = 1;

        int res = 0;
        int curr = 0;

        int start = 0, end = 0;

        while (end < k)
        {
            if (vowels[s[end] - 'a'] == 1)
                curr++;

            end++;
        }

        res = curr;

        while (end < s.size())
        {
            if (vowels[s[end] - 'a'] == 1)
                curr++;
            end++;
            if (vowels[s[start] - 'a'] == 1)
                curr--;
            start++;

            res = max(res, curr);
        }

        return res;
    }
};
