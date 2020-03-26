// https://leetcode.com/problems/k-closest-points-to-origin/


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if(K==points.size())
            return points;
        vector<pair<int,int>> A(points.size());
        for(int i=0;i<points.size();i++)
        {
            A[i].first=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            A[i].second=i;
        }
        
        sort(A.begin(),A.end());
        
        vector<vector<int>> B;
        
        for(int i=0;i<K;i++)
            B.push_back(points[A[i].second]);
        
        return B;
        
    }
};