// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if(arr.size()==1)
            return arr[0];
        int value=1;
        int pre=arr[0];
        for(int i=1;i<arr.size();i++)
            if(arr[i]==arr[i-1])
                value++;
            else  
                if(value>arr.size()/4)
                    return pre;
                else
                {
                    pre=arr[i];
                    value=1;
                }
        
        return pre;
    }
};