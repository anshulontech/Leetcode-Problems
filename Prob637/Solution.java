// Approach 1:-

class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> q=new LinkedList<>();
        
        List<Double> res= new ArrayList<Double>();
        
        q.add(root);
        
        while(!q.isEmpty()) {
            int n=q.size();
            
            Double sum=0.00;
            
            for(int i=0;i<n;i++) {
                TreeNode temp=q.poll();
                
                sum+=temp.val;
                if(temp.left!=null)
                    q.add(temp.left);
                if(temp.right!=null)
                    q.add(temp.right);
            }
            
            sum/=n;
            
            res.add(sum);
        }
        
        return res;
    }
}