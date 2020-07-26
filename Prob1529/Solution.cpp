// Approach 1 :-

class Solution
{
public:
    int minFlips(string target)
    {
        int res = 0;

        int start = 0;
        while (start < target.size() && target[start] == '0')
            start++;

        int end = target.size() - 1;

        while (end >= start)
        {
            char temp = target[end];

            while (end >= start && target[end] == temp)
                end--;

            res++;
        }

        return res;
    }
};