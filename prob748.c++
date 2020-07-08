// https://leetcode.com/problems/shortest-completing-word/description/

// Time Complexity:-O(N+M*l). --N=s.size(), M= words.size() & l is avg length of word in words.
// Space Compleixty:-O(N+M*l).

// Approach:-
//     Initially we will store the count of each word of words in a hash map and do the same thing for the s. Now we 
// will again traverse the map of words one by one and check for the min length string which contains all the words 
// in string s.

class Solution
{
public:
    string shortestCompletingWord(string s, vector<string> &words)
    {
        vector<unordered_map<char, int>> store(words.size());
        for (int i = 0; i < words.size(); i++)
        {
            auto &curr = store[i];
            for (int j = 0; j < words[i].size(); j++)
                curr[words[i][j]]++;
        }

        unordered_map<char, int> ref;
        for (int i = 0; i < s.size(); i++)
            if (isalpha(s[i]))
                ref[tolower(s[i])]++;

        int index = 0, len = INT_MAX;

        for (int i = 0; i < store.size(); i++)
        {
            int flag = 0;
            for (auto x : ref)
                if (x.second > store[i][x.first])
                {
                    flag = 1;
                    break;
                }

            if (flag == 0 && len > words[i].size())
            {
                len = words[i].size();
                index = i;
            }
        }

        return words[index];
    }
};