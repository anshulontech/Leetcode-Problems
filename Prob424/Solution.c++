// Link To Problem:-
// https://leetcode.com/problems/longest-repeating-character-replacement/

// METHOD 1:-

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int start = 0;
        vector<int> store(26);
        int max_length = 0;
        int max_count = 0;

        for (int end = 0; end < s.size(); end++)
        {
            store[s[end] - 'A']++;
            int curr_count = store[s[end] - 'A'];
            max_count = max(max_count, curr_count);

            while (end - start - max_count + 1 > k)
            {
                store[s[start] - 'A']--;
                start++;
            }

            max_length = max(max_length, end - start + 1);
        }

        return max_length;
    }
};