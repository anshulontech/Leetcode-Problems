// https://leetcode.com/problems/last-stone-weight/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
//     We are going to make the max heap of the given vector and that pop up the max two elements and than perform the 
// operation that was given and that if any result will obtain than insert that one to the heap again and perform same till 
// size of the heap is not less than 2. If size is 1 than return the front element and if size is 0 than return 0.
        
        
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
         make_heap(stones.begin(),stones.end());
         while(stones.size()>1) {
            int max1=stones.front();
                pop_heap(stones.begin(),stones.end());
                stones.pop_back();
             
             int max2=stones.front();
                 pop_heap(stones.begin(),stones.end());
                stones.pop_back();
            
            if(max1!=max2){
                int i=max1-max2;
                stones.push_back(i);
                push_heap(stones.begin(),stones.end());
                
            }
        }
         if(stones.size()==1){
                 return(stones.front());
             }
             else
                 return 0;
    }
   
};