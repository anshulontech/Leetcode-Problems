// Link To Problem:-
// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/

// Solution 1:-

class Solution
{
public:
    bool checkValid(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> set;

            for (int j = 0; j < n; j++)
                if (set.find(matrix[i][j]) != set.end())
                    return false;
                else
                    set.insert(matrix[i][j]);
        }

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> set;

            for (int j = 0; j < n; j++)
                if (set.find(matrix[j][i]) != set.end())
                    return false;
                else
                    set.insert(matrix[j][i]);
        }

        return true;
    }
};

// Solution 2:-

class Solution
{
public:
    bool checkValid(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), pos;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pos = abs(matrix[i][j]) - 1;
                if (matrix[i][pos] < 0)
                    return false;

                matrix[i][pos] *= -1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pos = abs(matrix[j][i]) - 1;
                if (matrix[pos][i] > 0)
                    return false;

                matrix[pos][i] *= -1;
            }
        }

        return true;
    }
};