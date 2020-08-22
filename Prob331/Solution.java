// Approach 1:-

class Solution {
    private int index=0;
    private boolean res=true;
    
    public boolean isValidSerialization(String preorder) {
        preOrder(preorder);
        
        return index>=preorder.length() && res;
    }
    
    void preOrder(String preorder) {
        if(index>=preorder.length()) {
            res=false;
            return ;
        }
        
        int i=index;
        
        while(i<preorder.length() && preorder.charAt(i)!=',')
            i++;
        
        String temp=preorder.substring(index,i);
        index=i+1;
        
        if(temp.equals("#"))
            return ;
        
        preOrder(preorder);
        preOrder(preorder);
    }
}