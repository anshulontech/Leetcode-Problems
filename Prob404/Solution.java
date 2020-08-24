// Approach 1:-

class Solution {
    private int sum=0;
    public int sumOfLeftLeaves(TreeNode root) {
        traversal(root,false);
        
        return sum;
    }
    
    private void traversal(TreeNode root,boolean isLeft) {
        if(root==null)
            return ;
        
        if(isLeft && root.left==null && root.right==null) {
            sum+=root.val;
            return;
        }
        
        traversal(root.left,true);
        traversal(root.right,false);
    }
}