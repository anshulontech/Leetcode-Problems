// Approach 1:-

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int pointer = 0;

        while (pointer < bits.size() - 1)
        {
            if (bits[pointer] == 1)
                pointer += 2;
            else
                pointer++;
        }

        return pointer == bits.size() - 1;
    }
};