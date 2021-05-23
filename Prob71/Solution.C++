// Link To Problem:-
// https://leetcode.com/problems/simplify-path/

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> store;

        int i = 0;

        while (i < path.size())
        {
            if (path[i] == '/')
            {
                i++;
                continue;
            }
            if (i + 1 < path.size() && path[i] == '.' && path[i + 1] == '.')
                if ((i + 2) == path.size() || path[i + 2] == '/')
                {
                    if (!store.empty())
                        store.pop_back();
                    i = i + 2;
                    continue;
                }
            if ((i + 1) < path.size() && path[i] == '.' && path[i + 1] == '/')
            {
                i++;
                continue;
            }
            if (i == path.size() - 1 && path[i] == '.')
            {
                i++;
                continue;
            }

            int prev = i;
            while (i < path.size() && path[i] != '/')
                i++;

            store.push_back(path.substr(prev, i - prev));
            i++;
        }

        string res = "";

        if (store.size() == 0)
            return "/";

        for (int i = 0; i < store.size(); i++)
        {
            res += '/';
            res += store[i];
        }

        return res;
    }
};