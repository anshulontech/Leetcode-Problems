// https://leetcode.com/problems/next-greater-element-i/

int find(vector<int> ,int );

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A;
        for(int i=0;i<nums1.size();i++)
        {
            int max=nums1[i];
            int index=find(nums2,max);
            for(int j=index+1;j<nums2.size();j++)
                if(nums2[j]>max)
                {
                    max=nums2[j];
                    break;
                }
            
            if(max==nums1[i])
                A.push_back(-1);
            else
                A.push_back(max);
        }
        
        
        return A;
    }
};

int find(vector<int> A,int value)
{
    for(int i=0;i<A.size();i++)
        if(A[i]==value)
            return i;
    
    return -1;
}