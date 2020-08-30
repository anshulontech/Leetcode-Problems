// Approach 1:-

class Solution {
    public List<Integer> pancakeSort(int[] A) {
        List<Integer> res=new ArrayList<>();
        int x,i;
        for(x=A.length;x>0;x--) {
            for(i=0;A[i]!=x;i++);
            
            reverse(A,i+1);
            res.add(i+1);
            reverse(A,x);
            res.add(x);
        }
        
        return res;
    }
    
    private void reverse(int[] A,int k) {
        for(int i=0,j=k-1;i<j;i++,j--) {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
}