// Solution:-

class Solution
{
public:
    string getHappyString(int n, int k)
    {
        vector<string> res;
        queue<string> q;
        q.push("a");
        q.push("b");
        q.push("c");

        while (!q.empty())
        {
            string s = q.front();
            q.pop();

            if (s.length() == n)
            {
                res.push_back(s);
                continue;
            }

            string s1 = "", s2 = "";

            if (s[s.length() - 1] == 'a')
            {
                s1 = s + 'b';
                s2 = s + 'c';
            }
            if (s[s.length() - 1] == 'b')
            {
                s1 = s + 'a';
                s2 = s + 'c';
            }
            if (s[s.length() - 1] == 'c')
            {
                s1 = s + 'a';
                s2 = s + 'b';
            }

            if (s1.length() <= n)
                q.push(s1);

            if (s2.length() <= n)
                q.push(s2);
        }

        if (k - 1 >= res.size())
            return "";
        else
            return res[k - 1];
    }
};