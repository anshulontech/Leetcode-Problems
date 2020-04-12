// https://leetcode.com/problems/min-stack/submissions/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     We will make 2 different stack named permanant and the other is aux(---auxilliry)> The permanant stack go as usually 
// the normal stack will go but the aux stack will get value only and only value the value inserted is less than or equal to 
// top most vaue and this stack was their just to return its minimum value.So when it minimum value is need we will get from 
// the top of the aux stack. 
    
// Operations will work as follows:-
// 1.INSERT:- The value will be inserted normally to the permanant stack while will be inserted in aux stack only when it will bw less than its top most value or aux stack is empty.
    
// 2.REMOVE:- Normally removed from the permamant stack while if the top of permanant stack and the aux stack are same than it will be removed from both of them else will be remove only from the permanant stack.
    
// 3.Top:- Just get the top most value of the permanant stack. No include of aux stack.
    
// 4.getMin:- top value of the aux stack represents the minimum value. No requirment of permanant stack. 
    
    
class MinStack {
public:
    
    stack<int> permanant;
    stack<int> aux;

    MinStack() {
    }
    
    void push(int x) {
        permanant.push(x);
        if(aux.empty()||aux.top()>=x) 
            aux.push(x);
    }
    
    void pop() {
        if(permanant.top()==aux.top())
            aux.pop();
        
        permanant.pop();
        
    }
    
    int top() {
        
        return permanant.top();
        
    }
    
    int getMin() {
        return aux.top();
    }
};