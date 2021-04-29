// Link To Problem:-
// https://leetcode.com/problems/count-and-say/submissions/

class Solution
{
public:
    string countAndSay(int n)
    {
        int temp1 = 1;
        string s = "1";

        while (temp1 != n)
        {
            string temp = "";
            for (int i = 0; i < s.size(); i++)
            {
                int count = 1;
                int k = i + 1;
                while (i < s.size() && s[i] == s[k])
                {
                    count++;
                    k++;
                }

                temp.insert(temp.size(), to_string(count));
                temp.insert(temp.size(), s.substr(i, 1));
                i = k - 1;
            }

            s = temp;
            temp1++;
        }

        return s;
    }
};