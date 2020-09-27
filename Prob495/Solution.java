// Approach 1:-

class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int res = 0, n = timeSeries.length;

        if (n < 1)
            return 0;

        for (int i = 1; i < n; i++)
        {
            res += Math.min(timeSeries[i] - timeSeries[i - 1], duration);
        }

        return res + duration;
    }
}