// Approach 1:-

class Solution {
    private int res=0,even =0,odd=0;
    public int pseudoPalindromicPaths (TreeNode root) {
        int[] arr = new int[9];
        
        traverse(root,arr);
        
        return res;
    }
    
    public void traverse(TreeNode root,int[] arr) {
        if(root==null)
            return ;
        
        arr[root.val-1]+=1;
        
        if(arr[root.val-1]%2==0) {
            even++;
            if(odd>0)
                odd--;
        }
        else {
            odd++;
            if(even>0)
                even--;
        }
        
        if(root.left==null && root.right==null) {
            if(odd<2)
                res++;
        }
        else {
            traverse(root.left,arr);
            traverse(root.right,arr);
        }
        
        arr[root.val-1]-=1;
        
        if(arr[root.val-1]%2==0) {
            even++;
            odd--;
        }
        else {
            odd++;
            even--;
        }
    }
}


// Appraoch 2:-

class Solution {
    private int res=0,odd=0;
    public int pseudoPalindromicPaths (TreeNode root) {
        int[] arr = new int[9];
        
        traverse(root,arr);
        
        return res;
    }
    
    public void traverse(TreeNode root,int[] arr) {
        if(root==null)
            return ;
        
        arr[root.val-1]+=1;
        
        if(arr[root.val-1]%2==0) {
            if(odd>0)
                odd--;
        }
        else
            odd++;
        
        if(root.left==null && root.right==null) {
            if(odd<2)
                res++;
        }
        else {
            traverse(root.left,arr);
            traverse(root.right,arr);
        }
        
        arr[root.val-1]-=1;
        
        if(arr[root.val-1]%2==0)
            odd--;
        else
            odd++;
    }
}
