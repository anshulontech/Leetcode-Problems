// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Time Complexity:-O(N^2).
// Space Complexity:-O(1).
    
// Approach:-
//     In this we are using brute force approach to find for each value as buying value that what will be it's max profit. 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        
        int N=prices.size();
        
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
                if((prices[j]-prices[i])>max_profit)
                    max_profit=prices[j]-prices[i];
        
        
        
        return max_profit;
                
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
//     In this what we are going to do is that we are start traversing the vector with min price as INT_MIN if we will 
// encounter with orice less than min price than we will update the value of min price else check that if we will sell
// at that time than is profit will be greater than previous one or not and if it will than we will update the answer
// else move forward.

class Solution
{
public:
    int maxProfit(vector<int> &price)
    {
        int min_price = INT_MAX;
        int max_profit = 0;

        int N = price.size();

        for (int i = 0; i < N; i++)
            if (price[i] < min_price)
                min_price = price[i];
            else if (price[i] - min_price > max_profit)
                max_profit = price[i] - min_price;

        return max_profit;
    }
};