// Link To The Problem:-
// https://leetcode.com/problems/smallest-value-of-the-rearranged-number/

// Solution:-

class Solution
{
public:
    long long smallestNumber(long long num)
    {
        if (num == 0)
            return 0;
        if (num < 0)
        {
            num *= -1;
            string temp = to_string(num);
            sort(temp.begin(), temp.end());
            reverse(temp.begin(), temp.end());

            num = mystoi(temp);

            return -1 * num;
        }

        string temp = to_string(num);

        sort(temp.begin(), temp.end());

        int idx = 0, n = temp.size();

        if (temp[0] == '0')
        {

            while (idx < n && temp[idx] == '0')
                idx++;

            temp[0] = temp[idx];
            temp[idx] = '0';
        }

        return mystoi(temp);
    }

    long long mystoi(string &s)
    {
        long long num = 0;

        for (auto x : s)
            num = num * 10 + (x - '0');

        return num;
    }
};