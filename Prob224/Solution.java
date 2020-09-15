// Approach 1:-

class Solution {
    public int calculate(String s) {
        Stack<Integer> store = new Stack<Integer> ();
        
        int res=0,num=0,sign=1;
        
        for(int i=0;i<s.length();i++) 
            if(Character.isDigit(s.charAt(i)))
                num=num*10+ (int)(s.charAt(i)-'0');
            else if(s.charAt(i)=='+' || s.charAt(i)=='-') {
                res+=sign*num;
                num=0;
                sign = (s.charAt(i)=='+') ? 1 : -1;
            }
                else if(s.charAt(i)=='(') {
                    store.push(res);
                    store.push(sign);
                    
                    sign=1;
                    res=0;
                }
                    else if(s.charAt(i)==')') {
                        res+=sign*num;
                        num=0;
                        res*=store.pop();
                        res+=store.pop();
                    }
            
        if(num!=0)
            res+=sign*num;
            
        return res;
    }
}