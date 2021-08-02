// Solution:-

class Solution
{
public:
    string maximumNumber(string num, vector<int> &change)
    {
        int k = 1;
        for (auto &x : num)
            if ((x - '0') < change[x - '0'])
            {
                x = change[x - '0'] + '0';
                k = 2;
            }
            else if ((x - '0') == change[x - '0'])
                continue;
            else if (k == 2)
                break;

        return num;
    }
};