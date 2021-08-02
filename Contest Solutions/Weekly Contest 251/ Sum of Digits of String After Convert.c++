// Solution:-

class Solution
{
public:
    int getLucky(string s, int k)
    {
        string temp = "";

        for (auto x : s)
            temp += to_string(x - 'a' + 1);

        while (k--)
            temp = helper(temp);

        return stoi(temp);
    }

    string helper(string s)
    {
        int sum = 0;

        for (auto x : s)
            sum += (x - '0');

        return to_string(sum);
    }
};