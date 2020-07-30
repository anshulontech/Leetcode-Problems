// Approach 1:-

class Solution
{
public:
    bool canTransform(string start, string end)
    {
        int i = 0, j = 0, m = start.size(), n = end.size();

        if (m != n)
            return false;

        while (i <= m && j <= n)
        {
            while (i < m && start[i] == 'X')
                i++;
            while (j < n && end[j] == 'X')
                j++;

            if (i == m && j == n)
                return true;

            if ((start[i] == 'L' && end[j] == 'L' && i >= j) || (start[i] == 'R' && end[j] == 'R' && i <= j))
                i++, j++;
            else
                return false;
        }

        return i == j;
    }
};