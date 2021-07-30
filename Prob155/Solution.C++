// Link To Problem:-
// https://leetcode.com/problems/min-stack/submissions/

// METHOD 1:-

class MinStack
{
public:
    stack<int> permanant;
    stack<int> aux;

    MinStack()
    {
    }

    void push(int x)
    {
        permanant.push(x);
        if (aux.empty() || aux.top() >= x)
            aux.push(x);
    }

    void pop()
    {
        if (permanant.top() == aux.top())
            aux.pop();

        permanant.pop();
    }

    int top()
    {

        return permanant.top();
    }

    int getMin()
    {
        return aux.top();
    }
};