// https://leetcode.com/problems/two-city-scheduling/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int amount=0;
        vector<pair<int,int>> A(costs.size());
        for(int i=0;i<costs.size();i++)
        {
            A[i].first=costs[i][1]-costs[i][0];
            A[i].second=i;
        }
        
        sort(A.begin(),A.end());
        
        for(int i=0;i<A.size()/2;i++)
            amount+=costs[A[i].second][1];
        for(int i=A.size()/2;i<A.size();i++)
            amount+=costs[A[i].second][0];
        
        return amount;
    }
};