// https://leetcode.com/problems/find-k-closest-elements/submissions/

// Time Complexity:-O( log(N)+k).
// Space Complexity:-O(1).
    
// Approach:-
//     Initially we will find the index of the number x. If the number was there than just get it's index while if it was not 
// there than we will collect it's lower bound. Now after getting this we initialize two vectors named left and right as shown 
// in the code. Now until condition 1 we will change the value of left and the right such that we will get nearer numbers in 
// the set of array between left and right. Now on termination of the loop if k>0 than with the help of condition 2 we will 
// again update the value of left or right according to condition 3. At last we ill run a loop from the left +1 till right to 
// store the numbers in increasing order in vector store and than return the store vector as final result.
        
        
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> store;
        
        int index=binarysearch(arr,x,0,arr.size()-1);
        
        cout<<index;
        
        int left=index,right=index+1;
        while(k>0 && left>=0 && right<arr.size() ) // condition 1.
            if((x-arr[left])<=(arr[right]-x))
            {
                left--;
                k--;
            }
            else
            {
                right++;
                k--;
            }
        
        
        if(k>0) // condition 2.
            if(left<0) // condition 3.
                right+=k;
            else
                left-=k;
        
        left++;
        
        for(;left<right;left++)
            store.push_back(arr[left]);      
        
        return store;
        
    }
    
    int binarysearch(vector<int> & arr, int x ,int start ,int end)
    {
        if(start>end)
            return end;
                
        int mid=start+(end-start)/2;
        
        if(arr[mid]==x)
            return mid;
        
        if(arr[mid]>x)
            return binarysearch(arr,x,start,mid-1);
        else
            return binarysearch(arr,x,mid+1,end);
    }
};