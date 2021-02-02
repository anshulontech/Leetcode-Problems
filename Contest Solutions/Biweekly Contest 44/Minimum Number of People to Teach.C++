// Solution:-

class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        unordered_map<int, unordered_set<int>> languagesMap;
        int k = languages.size();

        for (int i = 0; i < k; i++)
            for (auto l : languages[i])
                languagesMap[i + 1].insert(l);

        k = friendships.size();

        vector<bool> alreadyCan(k, false);
        for (int j = 1; j <= n; j++)
            for (int i = 0; i < k; i++)
                if (languagesMap[friendships[i][0]].find(j) != languagesMap[friendships[i][0]].end() && languagesMap[friendships[i][1]].find(j) != languagesMap[friendships[i][1]].end())
                    alreadyCan[i] = true;

        int minTeach = INT_MAX;

        for (int i = 1; i <= n; i++)
        {
            unordered_set<int> teachSet;

            for (int j = 0; j < k; j++)
            {
                if (alreadyCan[j])
                    continue;
                if (!(languagesMap[friendships[j][0]].find(i) != languagesMap[friendships[j][0]].end()))
                    teachSet.insert(friendships[j][0]);
                if (!(languagesMap[friendships[j][1]].find(i) != languagesMap[friendships[j][1]].end()))
                    teachSet.insert(friendships[j][1]);
            }

            minTeach = min((int)teachSet.size(), minTeach);
        }

        return minTeach;
    }
};