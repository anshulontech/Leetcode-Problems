// Link To The Problem:-
// https://leetcode.com/problems/design-bitset/

// Solution:-

class Bitset
{
    vector<bool> bits;
    int zeroes = 0, ones = 0;
    bool isFlipped = false;

public:
    Bitset(int size)
    {
        bits.resize(size, 0);
        zeroes = size;
        ones = 0;
    }

    void fix(int idx)
    {
        if (isFlipped)
        {
            if (!bits[idx])
                return;

            ones--;
            zeroes++;
            bits[idx] = false;
        }
        else
        {
            if (bits[idx])
                return;

            ones++;
            zeroes--;
            bits[idx] = true;
        }
    }

    void unfix(int idx)
    {
        if (isFlipped)
        {
            if (bits[idx])
                return;

            ones++;
            zeroes--;
            bits[idx] = true;
        }
        else
        {
            if (!bits[idx])
                return;

            ones--;
            zeroes++;
            bits[idx] = false;
        }
    }

    void flip()
    {
        isFlipped = !isFlipped;
    }

    bool all()
    {
        if (isFlipped)
            return ones == 0;
        else
            return zeroes == 0;
    }

    bool one()
    {
        if (isFlipped)
            return zeroes;
        else
            return ones;
    }

    int count()
    {
        if (isFlipped)
            return zeroes;
        else
            return ones;
    }

    string toString()
    {
        if (isFlipped)
        {
            string temp = "";
            for (auto x : bits)
                if (x)
                    temp += '0';
                else
                    temp += '1';

            return temp;
        }
        else
        {
            string temp = "";
            for (auto x : bits)
                if (x)
                    temp += '1';
                else
                    temp += '0';

            return temp;
        }
    }
};