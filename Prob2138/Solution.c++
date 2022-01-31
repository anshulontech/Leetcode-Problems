// Link To Problem:-
// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/

// Solution:-

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string> res;
        int n = s.size();

        for (int i = 0; i < n;)
        {
            string temp = "";
            for (int x = 0; x < k; x++)
                if (i < n)
                    temp += s[i++];
                else
                    temp += fill;

            res.push_back(temp);
        }

        return res;
    }
};