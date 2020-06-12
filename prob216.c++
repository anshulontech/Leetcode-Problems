// https://leetcode.com/problems/combination-sum-iii/

// Time Complexity:-O(N^2).
// Space Complexity:-O(k).
    
// Approach:-
//     Using the concept of backtracking and insert the elements in the temp vaector till it's size will not become 
// greater than k or sum of elements will not become greater than n. On the Case when size become k and sum become 
// target we will add than vector to the result else if any one of them goes high than we will retur from that condition.

class Solution {
private:
    int target,limit;
    vector<int> temp;
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        target=n,limit=k;
        
        for(int i=1;i<10;i++) {
            int sum=i;
            temp.push_back(i);
            backTrack(sum,i,1);
            temp.pop_back();
        }
        
        return res;
    }
    
    void backTrack(int sum,int last,int size) {
        if(size>limit || sum>target)
            return ;
        
        if(sum==target && size==limit) {
            res.push_back(temp);
            return ;
        }
        
        for(int i=last+1;i<10;i++) {
            sum+=i;
            temp.push_back(i);
            backTrack(sum,i,size+1);
            sum-=i;
            temp.pop_back();
        }
        
        return ;
    }
};