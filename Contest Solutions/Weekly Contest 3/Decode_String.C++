// Solution:-

class Solution
{
private:
    int i = 0;

public:
    string decodeString(string s)
    {
        string res = "";
        int val = 0;

        for (; i < s.size(); i++)
            if (isdigit(s[i]))
                val = val * 10 + (s[i] - '0');
            else if (isalpha(s[i]))
                res += s[i];
            else if (s[i] == '[')
            {
                i++;
                string temp = decodeString(s);

                while (val)
                {
                    res += temp;
                    val--;
                }
            }
            else
                return res;

        return res;
    }
};