// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     We will run a loop in which we will find the total sum of salary and also the min and max salary and in last 
// we will substract the min and max salary from the total salary and than divide the resultant salary with number 
// of peoples -2.

class Solution {
public:
    double average(vector<int>& salary) {
        double min_salary=INT_MAX,max_salary=INT_MIN;
        double net_salary=0;
        
        for(int i=0;i<salary.size();i++) {
            min_salary=min(min_salary,(double)salary[i]);
            max_salary=max(max_salary,(double)salary[i]);
            net_salary+=(double)salary[i];
        }
        
        double n=salary.size()-2;
        
        return (net_salary-max_salary-min_salary)/n;
        
    }
};