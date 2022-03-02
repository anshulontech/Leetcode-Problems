// Link To The Problem:-
// https://leetcode.com/problems/capitalize-the-title/

// Solution:-

class Solution
{
public:
    string capitalizeTitle(string title)
    {
        int n = title.size();

        for (int i = 0; i < n; i++)
        {
            int idx = i;

            while (i < n && title[i] != ' ')
            {
                if (title[i] >= 'A' && title[i] <= 'Z')
                    title[i] = title[i] - 'A' + 'a';
                i++;
            }

            if ((i - idx) > 2)
                title[idx] = title[idx] - 'a' + 'A';
        }

        return title;
    }
};