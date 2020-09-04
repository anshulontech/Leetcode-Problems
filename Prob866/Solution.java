// Approach 1:-

class Solution {
    public int primePalindrome(int N) {
        if(N>=8 && N<=11)
            return 11;
        
        for(int x=1;x<100000;x++) {
            String s=Integer.toString(x),r=new StringBuilder(s).reverse().toString();
            int y=Integer.parseInt(s+r.substring(1));
            
            if(y>=N && isPrime(y)) return y;
        }
        
        return -1;
    }
    
    private boolean isPrime(int N) {
        if(N<2 || N%2==0) return N==2;
        
        for(int i=3;i*i<=N;i++)
            if(N%i==0)
                return false;
        
        return true;
    }
}