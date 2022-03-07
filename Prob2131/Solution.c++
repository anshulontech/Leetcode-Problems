// Link To The Problem:-
// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

// Solution:-

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int res = 0;
        unordered_map<string, int> map, smap;

        for (auto x : words)
        {
            if (x[0] == x[1])
                smap[x]++;
            else
            {
                string rev = reverseIt(x);

                if (map.find(rev) != map.end() && map[rev] != 0)
                {
                    res += 4;
                    map[rev]--;
                }
                else
                    map[x]++;
            }
        }

        bool isMidFind = false;

        for (auto x : smap)
            if (x.second % 2 == 0)
            {
                res += x.second * 2;
            }
            else
            {
                res += (x.second - 1) * 2;

                if (!isMidFind)
                {
                    res += 2;
                    isMidFind = true;
                }
            }

        return res;
    }

    string reverseIt(string &x)
    {
        string temp = x;

        reverse(temp.begin(), temp.end());

        return temp;
    }
};
