// Approach 1:-

class Solution {
    private TreeNode prev = null;
    private boolean isDone=false;
    public TreeNode insertIntoBST(TreeNode root, int val) {
        prev = null;
        TreeNode node= new TreeNode(val);
        
        if(root==null)
            return node;
        
        helper(root,val);
        
        if(prev.val>val)
            prev.left=node;
        else 
            prev.right=node;
        
        return root;
    }
    
    private void helper(TreeNode root, int val) {
        if(!isDone && root.val>val)
            if(root.left!=null)
                helper(root.left,val);
            else {
                prev=root;
                isDone=true;
            }
        else if(!isDone)
            if(root.right!=null)
                helper(root.right,val);
            else {
                prev=root;
                isDone=true;
            }
            
    }
}
    