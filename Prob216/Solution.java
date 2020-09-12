// Approach 1:-

class Solution {
    private int target,limit;
    private List<Integer> temp= new ArrayList<Integer>();
    private List<List<Integer>> res= new ArrayList<List<Integer>>();
    
    public List<List<Integer>> combinationSum3(int k, int n) {
        target=n;
        limit=k;
        
        for(int i=1;i<10;i++) {
            int sum=i;
            temp.add(i);
            backTrack(sum,i,1);
            temp.remove(0);
        }
        
        return res;
    }
    
    private void backTrack(int sum,int last,int size) {
        if(size>limit || sum>target)
            return ;
        
        if(sum==target && size==limit) {
            res.add(new ArrayList<Integer>(temp));
            return;
        }
        
        for(int i=last+1;i<10;i++) {
            sum+=i;
            temp.add(i);
            backTrack(sum,i,size+1);
            sum-=i;
            temp.remove(temp.size()-1);
        }
        
        return ;
    }
}