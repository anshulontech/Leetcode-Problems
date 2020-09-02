// Approach 1:-

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res= new LinkedList<>();;
        
        int N=nums.length;
        
        for(int i=0;i<N;i++) {
            
            for(int j=i+1;j<N;j++) {
                
                for(int k=j+1;k<N;k++) {
                    
                    if((nums[i]+nums[j]+nums[k])==0)
                        res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    
                    while(k<N-1 && nums[k]==nums[k+1])
                        k++;
                }
                while(j<N-1 && nums[j]==nums[j+1])
                    j++;
            }
            while(i<N-1 && nums[i]==nums[i+1])
                i++;
        }
        
        
        return res;
    }
}

// Approach 2:-

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res= new LinkedList<>();;
        
        int N=nums.length;
        
        for(int i=0;i<nums.length-2;i++) {
            int start=i+1,end=nums.length-1;
            int sum=nums[i]+nums[start]+nums[end];
            
            while(start<end) {
                sum=nums[i]+nums[start]+nums[end];
                
                if(sum<0)
                    start++;
                else
                    if(sum>0)
                        end--;
                    else {
                        res.add(Arrays.asList(nums[i],nums[start],nums[end]));
                        while(start<end && nums[start]==nums[start+1])
                            start++;
                        while(start<end && nums[end]==nums[end-1])
                            end--;
                        
                        start++;
                        end--;
                    }
            }

            
            while(i<nums.length-1 && nums[i]==nums[i+1])
                i++;
        }
        
        
        return res;
    }
}