// Approach 1:-

class Solution {
    private List<Integer> res;
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        res=new ArrayList<Integer>();
        traversal(root1);
        traversal(root2);
        
        Collections.sort(res);
        
        return res;
    }
    
    private void traversal(TreeNode root) {
        if(root==null)
            return ;
        
        res.add(root.val);
        traversal(root.left);
        traversal(root.right);
    }
}

// Approach 2:-

class Solution {
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> first=new ArrayList<Integer>();
        List<Integer> second=new ArrayList<Integer>();
        List<Integer> res=new ArrayList<Integer>();
        
        inorder(root1,first);
        inorder(root2,second);
        
        merge_array(res,first,second);
        
        return res;
    }
    
    private void inorder(TreeNode root,List<Integer> arr) {
        if(root==null)
            return;
        
        inorder(root.left,arr);
        arr.add(root.val);
        inorder(root.right,arr);
    }
    
    private void merge_array(List<Integer> res,List<Integer> first,List<Integer> second) {
        int i=0,j=0;
        
        while(i<first.size() && j<second.size()) {
            if(first.get(i)<=second.get(j))
                res.add(first.get(i++));
            else
                res.add(second.get(j++));
        }
        
        while(i<first.size())
            res.add(first.get(i++));
        
        while(j<second.size())
            res.add(second.get(j++));
    }
}

// Approach 3:-

class Solution {
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        Stack<TreeNode> S1 = new Stack<TreeNode> ();
        Stack<TreeNode> S2 = new Stack<TreeNode> ();
        List<Integer> res= new ArrayList<Integer>();
        
        TreeNode temp=root1;
        
        while(temp!=null) {
            S1.push(temp);
            temp=temp.left;
        }
        
        temp=root2;
        
        while(temp!=null) {
            S2.push(temp);
            temp=temp.left;
        }
        
        TreeNode top;
        
        while(!S1.empty() && !S2.empty())
            if(S1.peek().val<=S2.peek().val) {
                top=S1.peek();
                S1.pop();
                res.add(top.val);
                top=top.right;
                
                while(top!=null) {
                    S1.push(top);
                    top=top.left;
                }
            }
            else {
                top=S2.peek();
                S2.pop();
                res.add(top.val);
                top=top.right;
                
                while(top!=null) {
                    S2.push(top);
                    top=top.left;
                }
            }
        
        while(!S1.empty()) {
            top=S1.peek();
                S1.pop();
                res.add(top.val);
                top=top.right;
                
                while(top!=null) {
                    S1.push(top);
                    top=top.left;
                }
        }
        
        while(!S2.empty()) {
            top=S2.peek();
                S2.pop();
                res.add(top.val);
                top=top.right;
                
                while(top!=null) {
                    S2.push(top);
                    top=top.left;
                }
        }
        
        return res;
    }
}