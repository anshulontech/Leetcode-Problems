// https://leetcode.com/problems/kth-largest-element-in-a-stream/3

// Time Complexity:-O(N+M).
// Space Complexity:-O(N).
    
//     Where N is number of elements in nums and M is number of times add function is called.
    
// Approach:-
//     We will build a min heap in this question using priority queue and maintain the size equal to k the top element of the 
// priority queue is the kth lagrest element in the list.

class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> store;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int i=0;i<nums.size();i++)
            store.push(nums[i]);
        
        while(store.size()>k)
            store.pop();
    }
    
    int add(int val) {
        store.push(val);
        while(store.size()>size)
            store.pop();
        
        return store.top();
    }
};