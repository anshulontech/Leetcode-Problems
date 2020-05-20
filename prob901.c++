// https://leetcode.com/problems/online-stock-span/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     For this we will two stack one will take the value of price and the other one will store the stock for that 
// price. Now when we encounter with a new price than we will check in the stack untill the price will become less 
// than the stack top price. To calculate the stock of that price the other stack will be useful as this will help 
// us to state the stack top's price's stock and hence we will add that one to current stock .
    
class StockSpanner {
private:
    stack<int> prices,weights;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int w=1;
        while(!prices.empty() && prices.top()<=price)
        {
            prices.pop();
            w+=weights.top();
            weights.pop();
        }
        
        prices.push(price);
        weights.push(w);
        
        return w;
    }
};