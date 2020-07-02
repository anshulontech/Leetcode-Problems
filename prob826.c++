// https://leetcode.com/problems/most-profit-assigning-work/description/

// Time Complexity:-O(N*log(N)+M*log(M)).
// Space Complexity:-O(N).
    
// Approach:-
//     Initially we will make a vector of pair to store the profit value for corresponding difficulty . And after this 
// we will sort this vector as well as worker vector. Now we will start to traverse the worker vector and and for each 
// difficulty we will taking a best profit value and on every new worker we will update the best by traversing the 
// store vector which store the difficulty in increasing order. After each worker end we will upadte the result with 
// the best profit till that time.

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        vector<pair<int, int>> store;
        int N = profit.size();

        for (int i = 0; i < N; i++)
            store.push_back(make_pair(difficulty[i], profit[i]));

        sort(store.begin(), store.end());
        sort(worker.begin(), worker.end());

        int res = 0;
        int i = 0, best = 0;

        for (auto skill : worker)
        {
            while (i < N && skill >= store[i].first)
                best = max(best, store[i++].second);

            res += best;
        }

        return res;
    }
};