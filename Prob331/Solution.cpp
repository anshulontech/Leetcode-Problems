// Approach 1:-

class Solution
{
private:
    int index = 0;
    bool res = true;

public:
    bool isValidSerialization(string preorder)
    {

        preOrder(preorder);

        return index >= preorder.size() && res ? true : false;
    }

    void preOrder(string &preorder)
    {
        if (index >= preorder.size())
        {
            res = false;
            return;
        }
        int i = index;

        while (i < preorder.size() && preorder[i] != ',')
            i++;

        string temp = preorder.substr(index, i - index);
        index = i + 1;

        if (temp == "#")
            return;

        preOrder(preorder);

        preOrder(preorder);
    }
};
