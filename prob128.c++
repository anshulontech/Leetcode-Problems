// https://leetcode.com/problems/longest-consecutive-sequence/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this first we will store the count of each numbr in a map. Now we will again traverse the array and for each 
// integer we will go forward nad backward till their count will not become equal to zero . Npow we will check the length 
// and if it will be greater than previous one than we will update the answer else just make their all count to 0. At 
// last the max count is the ans.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> store;
        int res=0;
        
        for(int i=0;i<nums.size();i++) 
            store[nums[i]]++;
        
        
        for(int i=0;i<nums.size();i++)
            if(store[nums[i]]!=0) {
                
                int curr=1;
                int k=1;
                
                while(store[nums[i]+k]!=0) {
                    store[nums[i]+k]=0;
                    k++;
                    curr++;
                }
                
                k=1;
                while(store[nums[i]-k]!=0) {
                    store[nums[i]-k]=0;
                    k++;
                    curr++;
                }
                
                if(curr>res)
                    res=curr;
            }
        
        return res;
    }
};

// Similar Approach as that of previous one but here we are not going to traverse the array again an we are going to traverse 
// the map again.

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> store;
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
            store[nums[i]]++;

        for (auto x : store)
        {
            int i = 1;
            int curr = 1;

            while (store.find(x.first + i) != store.end())
            {
                store.erase(store.find(x.first + i));
                i++;
                curr++;
            }

            i = 1;
            while (store.find(x.first - i) != store.end())
            {
                store.erase(store.find(x.first - i));
                i++;
                curr++;
            }

            if (curr > res)
                res = curr;
        }

        return res;
    }
};

Similar approach using set.

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> store;
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
            store.insert(nums[i]);

        for (auto x : store)
        {
            int i = 1;
            int curr = 1;

            while (store.find(x + i) != store.end())
            {
                store.erase(store.find(x + i));
                i++;
                curr++;
            }

            i = 1;
            while (store.find(x - i) != store.end())
            {
                store.erase(store.find(x - i));
                i++;
                curr++;
            }

            if (curr > res)
                res = curr;
        }

        return res;
    }
};