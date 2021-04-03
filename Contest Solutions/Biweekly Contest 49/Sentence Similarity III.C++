// Solution:-

class Solution
{
public:
    bool areSentencesSimilar(string s1, string s2)
    {
        vector<string> arr1, arr2;
        int n1 = s1.size(), n2 = s2.size();

        for (int i = 0; i < n1; i++)
        {
            int idx = i;
            while (i < n1 && s1[i] != ' ')
                i++;

            arr1.push_back(s1.substr(idx, i - idx));
        }

        for (int i = 0; i < n2; i++)
        {
            int idx = i;
            while (i < n2 && s2[i] != ' ')
                i++;

            arr2.push_back(s2.substr(idx, i - idx));
        }

        int start1 = 0, end1 = arr1.size() - 1, start2 = 0, end2 = arr2.size() - 1;

        while (start1 <= end1 && start2 <= end2)
        {
            int flag = 1;
            if (arr1[start1] == arr2[start2])
            {
                start1++, start2++;
                flag = 0;
            }
            if (arr1[end1] == arr2[end2])
            {
                end1--, end2--;
                flag = 0;
            }

            if (flag)
                break;
        }

        if (start1 > end1 || start2 > end2)
            return true;
        else
            return false;
    }
};