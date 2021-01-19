// Solution:-

class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        int len = data.size();

        for (int i = 0; i < len; i++)
        {
            int numofBytes = 0;
            int val = data[i];

            if (val > 255)
                return false;
            else if ((val & 128) == 0)
                numofBytes = 1;
            else if ((val & 224) == 192)
                numofBytes = 2;
            else if ((val & 240) == 224)
                numofBytes = 3;
            else if ((val & 248) == 240)
                numofBytes = 4;
            else
                return false;

            for (int j = 1; j < numofBytes; j++)
                if ((j + i) >= len)
                    return false;
                else if ((data[i + j] & 192) != 128)
                    return false;

            i += numofBytes - 1;
        }

        return true;
    }
};