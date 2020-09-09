// Approach 1:-

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int i = 0, j = 0;

        while (i < version1.size() && j < version2.size())
        {
            int start1 = i;
            while (i < version1.size() && version1[i] != '.')
                i++;

            int firstNum = stoi(version1.substr(start1, i - start1));

            int start2 = j;

            while (j < version2.size() && version2[j] != '.')
                j++;

            int secondNum = stoi(version2.substr(start2, j - start2));

            if (firstNum > secondNum)
                return 1;
            if (firstNum < secondNum)
                return -1;

            i++, j++;
        }

        while (i < version1.size())
        {
            int start = i;
            while (i < version1.size() && version1[i] != '.')
                i++;

            int num = stoi(version1.substr(start, i - start));

            if (num != 0)
                return 1;

            i++;
        }

        while (j < version2.size())
        {
            int start = j;
            while (j < version2.size() && version2[j] != '.')
                j++;

            int num = stoi(version2.substr(start, j - start));

            if (num != 0)
                return -1;

            j++;
        }

        return 0;
    }
};