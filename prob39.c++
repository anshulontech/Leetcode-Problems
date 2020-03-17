// https://leetcode.com/problems/combination-sum/

void toCombinetoTarget(vector<vector<int>> & ,vector<int> &,vector<int>& ,int ,int );

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.size()==NULL)
            return result;
        
        vector<int> combination;
        
        sort(candidates.begin(),candidates.end());
        
        toCombinetoTarget(result,combination,candidates,target,0);
        
        return result;
    }
};

void toCombinetoTarget(vector<vector<int>> & result,vector<int> &combination,vector<int>& candidates,int target,int start)
{
    if(target==0)
    {
        result.push_back(combination);
        return ;
    }
    
    for(int i=start;i<candidates.size();i++)
    {
        if(candidates[i]>target)
            break;
        
        combination.push_back(candidates[i]);
        toCombinetoTarget(result,combination,candidates,target-candidates[i],i);
        combination.pop_back();
    }
}