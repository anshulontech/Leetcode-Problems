// Approach 1:-

public class Codec {
    
    public String serialize(TreeNode root) {
        if(root==null)
            return "-1";
        
        return Integer.toString(root.val) + "," + serialize(root.left)+ "," + serialize(root.right);
    }
    
    public TreeNode deserialize(String s) {
        Queue<Integer> q = new LinkedList<>();
        buildQueue(s,q);
        
        return helper_deserialize(q);
    }
    
    private void buildQueue(String s,Queue<Integer> q) {
        int n=s.length();
        
        for(int i=0;i<n;i++) {
            int j=i+1;
            
            while(j<n && s.charAt(j)!=',')
                j++;
            
            q.add(Integer.parseInt(s.substring(i,j)));
            i=j;
        }
        
        return ;
    }
    
    private TreeNode helper_deserialize(Queue<Integer> q) {
        if(q.peek()==-1) {
            q.remove();
            return null;
        }
        
        TreeNode node = new TreeNode(q.peek());
        q.remove();
        node.left=helper_deserialize(q);
        node.right=helper_deserialize(q);
        
        return node;
    }
}