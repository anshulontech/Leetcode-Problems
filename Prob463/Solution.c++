// Link To Problem:-
// https://leetcode.com/problems/island-perimeter/

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &A)
    {
        int peri = 0;
        int count = 0;
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[i].size(); j++)
                if (A[i][j] == 1)
                {
                    count = 0;
                    if ((j - 1) >= 0 && A[i][j - 1] == 1)
                        count++;
                    if ((j + 1) < A[i].size() && A[i][j + 1] == 1)
                        count++;
                    if ((i - 1) >= 0 && A[i - 1][j] == 1)
                        count++;
                    if ((i + 1) < A.size() && A[i + 1][j] == 1)
                        count++;

                    peri = peri + 4 - count;
                }

        return peri;
    }
};