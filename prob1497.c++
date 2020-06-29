// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     As we know the value of remainder of each value comes out to be in between 0 to k-1 hence we will make a vector 
// of size of k and store the count of each remainder there , now after this this we will start to traverse the remainderFreq 
// array which stores the cout of each remainder  from index 1 till the mid , now if we have let say 4 elements of remainder 
// 1 than to fulfill the condition we should have 4 elements of remainder k-1 and so on for all remainders , so now we 
// will check that is this happens to be true for all remainder if it is than we will return true else if anywhere this 
// property breaks we will return false.

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderFreq(k);
        
        for(int i=0;i<arr.size();i++) {
            int remainder=arr[i]%k;
            
            if(remainder<0)
                remainder+=k;
            
            remainderFreq[remainder]++;
        }
        
        for(int i=1;i<k/2+1;i++)
            if(remainderFreq[i]!=remainderFreq[k-i])
                return false;
        
        return remainderFreq[0]%2==0;
    }
};