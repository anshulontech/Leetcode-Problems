// Link To Problem:-
// https://leetcode.com/problems/reshape-the-matrix/

// METHOD 1 : -

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        if (r * c != nums.size() * nums[0].size())
            return nums;

        vector<vector<int>> A(r, vector<int>(c));
        vector<int> B;

        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums[i].size(); j++)
                B.push_back(nums[i][j]);

        int k = 0;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                A[i][j] = B[k];
                k++;
            }

        return A;
    }
};

// METHOD 2:-

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        if (r * c != nums.size() * nums[0].size())
            return nums;

        vector<int> B;

        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums[i].size(); j++)
                B.push_back(nums[i][j]);

        int k = 0;
        nums.clear();
        nums.resize(r, vector<int>(c));

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                nums[i][j] = B[k];
                k++;
            }

        return nums;
    }
};