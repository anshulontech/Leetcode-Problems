// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/submissions/

Time Complexity:-O(k*log(k)).?
class Solution {
private:
    struct Compare  // To make heap min heap.
    {
        bool operator()(tuple<int,int,int> & t1, tuple<int,int,int> & t2){
            
            return ((get<0> (t1)+get<1>(t1))>(get<0> (t2)+get<1> (t2)));
        }
    };
    
    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        
        if(nums1.size()==0||nums2.size()==0||k<=0)
            return res;
        
        priority_queue< tuple<int,int,int> , vector<tuple<int,int,int>> , Compare> store;  // min heap implementation
         
        for(int i=0;i<min((int)nums1.size(),k);i++)  // storingelements in min_heap. min(k,nums1.size()) element are allowed
            store.push(make_tuple(nums1[i],nums2[0],0));
        
        while(k-- >0&&!store.empty())
        {
            tuple<int,int,int> front=store.top();
            
            res.push_back({get<0>(front),get<1> (front)});  // Inserting top element in the res.
            
            store.pop();
            if(get<2> (front)+1<nums2.size())//checking that if next pair of nums1[i] can enter or not if yes than we will enter it.
            {
                store.push(make_tuple(get<0> (front),nums2[get<2> (front)+1],get<2> (front)+1));
            }
        }
        
        return res;
    }
};
