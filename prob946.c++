// https://leetcode.com/problems/validate-stack-sequences/description/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this we will maintain a stack to store the pushed elements in the stack. Now att each step we will check 
// that is the top of the stack is equal to value represented by popped pointer , if this we will than we will pop 
// up the value from the stack and than increase the pointer and than check for the next one. At last we will check 
// that is the stack is empty or not if it is than it represents that we can make this sequence using stack else we 
// will not.

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> store;

        int i = 0, j = 0;

        for (; i < pushed.size(); i++)
        {
            if (!store.empty() && store.top() == popped[j])
                j++, store.pop(), i--;
            else
                store.push(pushed[i]);
        }

        while (!store.empty() && store.top() == popped[j])
            store.pop(), j++;

        return store.empty();
    }
};