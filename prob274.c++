// https://leetcode.com/problems/h-index/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> buckets(n+1);
        
        for(int c : citations)
            if(c>=n)
                buckets[n]++;
            else
                buckets[c]++;
        
        int count=0;
        for(int i=n;i>=0;i--) {
            count+=buckets[i];
            if(count>=i)
                return i;
        }
        
        return 0;
    }
};