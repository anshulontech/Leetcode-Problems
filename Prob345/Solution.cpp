// Approach 1:-

class Solution
{
public:
    string reverseVowels(string s)
    {
        vector<int> vowels(26, 0);
        vowels['a' - 'a'] = 1, vowels['e' - 'a'] = 1, vowels['i' - 'a'] = 1, vowels['o' - 'a'] = 1, vowels['u' - 'a'] = 1;

        int start = 0, end = s.size() - 1;

        while (start <= end)
        {
            while (start <= end && (!isalpha(s[start]) || vowels[tolower(s[start]) - 'a'] == 0))
                start++;

            while (start <= end && (!isalpha(s[end]) || vowels[tolower(s[end]) - 'a'] == 0))
                end--;

            if (start <= end)
                swap(s[start++], s[end--]);
        }
        return s;
    }
};