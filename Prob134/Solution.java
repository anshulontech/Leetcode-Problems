// Approach 1:-

class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int start=0,currentCost=0,totalCost=0;
        int n=gas.length;
        
        for(int i=0;i<n;i++) {
            totalCost+=gas[i]-cost[i];
            currentCost+=gas[i]-cost[i];
            if(currentCost<0) {
                currentCost=0;
                start=i+1;
            }
        }
        
        return totalCost<0 ? -1:start;
    }
}