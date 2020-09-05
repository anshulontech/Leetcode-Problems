// Approach 1:-

class Solution {
    private List<TreeNode> inorder;
    public void recoverTree(TreeNode root) {
        inorder=new ArrayList<TreeNode>();
        
        traversal(root);
        
        int first=-1,second=-1;
        
        for(int i=0;i<inorder.size()-1;i++) 
            if(inorder.get(i).val>inorder.get(i+1).val)
                if(first==-1)
                    first=i;
                else {
                    second=i+1;
                    break;
                }
        
        if(second==-1)
            swap(inorder.get(first),inorder.get(first+1));
        else
            swap(inorder.get(first),inorder.get(second));
        
        return;
    }
    
    private void traversal(TreeNode root) {
        if(root==null)
            return ;
        
        traversal(root.left);
        inorder.add(root);
        traversal(root.right);
    }
    
    private void swap(TreeNode A,TreeNode B) {
        int temp=A.val;
        A.val=B.val;
        B.val=temp;
    }
}

// Approach 2:-

class Solution {
    private TreeNode first;
    
    private TreeNode second;
    
    private TreeNode prevElement = new TreeNode(Integer.MIN_VALUE);
    
    public void recoverTree(TreeNode root) {
        traverse(root);
        
        int temp=first.val;
        first.val=second.val;
        second.val=temp;
    }
    
    private void traverse(TreeNode root) {
        if(root==null)
            return ;
        
        traverse(root.left);
        
        if(first==null && prevElement.val>root.val)
            first=prevElement;
        
        if(first!=null && prevElement.val>root.val)
            second=root;
        
        prevElement=root;
        
        traverse(root.right);
    }
}