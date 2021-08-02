// Solution:-

class Solution
{
public:
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        int n = students.size(), m = students[0].size();
        vector<vector<int>> score(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0;
                for (int k = 0; k < m; k++)
                    if (students[i][k] == mentors[j][k])
                        sum++;

                score[i][j] = sum;
            }
        }

        int res = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            int currScore = score[0][i];
            visited[i] = true;
            dfs(score, visited, currScore, res, 1, n);
            visited[i] = false;
        }

        return res;
    }

    void dfs(vector<vector<int>> &score, vector<bool> &visited, int &currScore, int &res, int idx, int &n)
    {
        if (idx >= n)
        {
            res = max(res, currScore);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            currScore += score[idx][i];
            visited[i] = true;
            dfs(score, visited, currScore, res, idx + 1, n);
            visited[i] = false;
            currScore -= score[idx][i];
        }

        return;
    }
};