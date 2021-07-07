// Link To Problem:-
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// METHOD 1:-

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        priority_queue<int> pq;

        int n = mat.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                pq.push(mat[i][j]);
                if (pq.size() > k)
                    pq.pop();
            }

        return pq.top();
    }
};