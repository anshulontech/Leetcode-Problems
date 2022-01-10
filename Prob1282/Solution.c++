// Link To Problem:-
// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &A)
    {
        vector<vector<int>> output;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] != 0)
            {
                vector<int> B;
                B.push_back(i);
                int temp = A[i];
                int j;
                for (j = i + 1; j < A.size() && A[i] != 1; j++)
                    if (temp == A[j] && A[j] != 0)
                    {
                        B.push_back(j);
                        A[i]--;
                        A[j] = 0;
                    }
                output.push_back(B);
            }
        }

        return output;
    }
};
