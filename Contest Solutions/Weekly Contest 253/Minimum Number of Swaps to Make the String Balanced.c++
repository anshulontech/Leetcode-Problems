// Solution:-

class Solution
{
public:
    int minSwaps(string s)
    {
        stack<char> stack;

        for (auto x : s)
            if (x == '[')
                stack.push(x);
            else if (!stack.empty() && stack.top() == '[')
                stack.pop();
            else
                stack.push(x);

        int size = stack.size();
        return size / 4 + ((size % 4 != 0) ? 1 : 0);
    }
};