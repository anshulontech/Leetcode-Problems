// Approach 1:-

class Solution {
    public char findTheDifference(String s, String t) {
        Map<String,Integer> store = new HashMap<String,Integer>();
        
        for(int i=0;i<s.length();i++) {
            String c=Character.toString(s.charAt(i));
            
            if(store.containsKey(c))
                store.put(c,store.get(c)+1);
            else
                store.put(c,1);
        }
        
        for(int i=0;i<t.length();i++) {
            String c=Character.toString(t.charAt(i));
            
            if((store.containsKey(c) && store.get(c)==0) || !(store.containsKey(c)))
                return t.charAt(i);
            else
                store.put(c,store.get(c)-1);
        }
        
        
        return 'a';
    }
}


// Approach 2:-

class Solution {
    public char findTheDifference(String s, String t) {
        int n = t.length() - 1;

        char c = t.charAt(n);

        for (int i = 0; i < n; i++)
        {
            c ^= s.charAt(i);
            c ^= t.charAt(i);
        }

        return c;
    }
}