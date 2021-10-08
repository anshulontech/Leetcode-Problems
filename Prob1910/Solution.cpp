// Link To Problem:-
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

// Solution:-

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        vector<char> temp;
        int k = part.size();
        for (auto x : s)
        {
            temp.push_back(x);

            if (temp.size() >= k && isMatch(temp, part))
            {
                int l = k;
                while (l--)
                    temp.pop_back();
            }
        }

        string res = "";
        for (auto x : temp)
            res += x;

        return res;
    }

    bool isMatch(vector<char> &temp, string &part)
    {
        int i = part.size() - 1, j = temp.size() - 1;

        while (i >= 0)
            if (part[i] == temp[j])
                i--, j--;
            else
                return false;

        return true;
    }
};