// Approach 1:-

class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        return (num > 0) && ((num - 1) % 3) == 0 && ((num - 1) & num) == 0;
    }
};