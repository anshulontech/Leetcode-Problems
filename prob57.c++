// https://leetcode.com/problems/insert-interval/submissions/

// Time Coomplexity:-O(N*log(N)).
// Space Complexity:-O(N).
    
// Approach:-
//     First Insert the new interval to the end of the intervals vector and than call a function to merger them which will 
// merge the whole vector. 
    
// Approch for merge function:-
//      If the size of the array is less than 2 than their is no need to merge hence we will return the intervals array 
// as given. Else we will first sort the array and than push_back first element of the intervals to a newely created vector 
// named output. Now we will run the loop from the first index of the intervals and check that is the values of first item 
// of that interval is less than or equal to second element of last element in vector output. If it was than we update the 
// value of second element of last element in vector output and just go as previous one but if it was not than we will add 
// that part of intervals to the output and than go as the previous one. When the loop end the to last element, result will 
// be in the output array hence we will return output as final answer.



class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        intervals=merge(intervals);
        return intervals;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return intervals;
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> output;
        int k=0;
        output.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++)
            if(output[k][1]>=intervals[i][0])
                output[k][1]=max(output[k][1],intervals[i][1]);
            else
            {
                output.push_back(intervals[i]);
                k++;
            }
            
        return output;
    }
};