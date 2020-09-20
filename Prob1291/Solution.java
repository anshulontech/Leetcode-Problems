// Approach 1:-

class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        
        String digits="123456789";
        
        List<Integer> res = new ArrayList<Integer>();
        
        int min_len=String.valueOf(low).length();
        int max_len=String.valueOf(high).length();
        
        for(int i=min_len;i<=max_len;i++)
            for(int j=0;j<10-i;j++) {
                int num=Integer.parseInt(digits.substring(j,i+j));
                if(num>=low && num<=high)
                    res.add(num);
            }
            
        return res;
    }
}