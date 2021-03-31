// Link To Problem:-
// https://leetcode.com/problems/integer-to-roman/

class Solution
{
public:
    string intToRoman(int num)
    {
        string s;
        while (num / 1000 != 0)
        {
            s.insert(s.size(), "M");
            num -= 1000;
        }
        if (num == 0)
            return s;
        if (num / 900 != 0)
        {
            s.insert(s.size(), "CM");
            num -= 900;
        }
        if (num == 0)
            return s;
        if (num / 500 != 0)
        {
            s.insert(s.size(), "D");
            num -= 500;
        }
        if (num == 0)
            return s;
        if (num / 400 != 0)
        {
            s.insert(s.size(), "CD");
            num -= 400;
        }
        if (num == 0)
            return s;
        while (num / 100 != 0)
        {
            s.insert(s.size(), "C");
            num -= 100;
        }
        if (num == 0)
            return s;
        if (num / 90 != 0)
        {
            s.insert(s.size(), "XC");
            num -= 90;
        }
        if (num == 0)
            return s;
        if (num / 50 != 0)
        {
            s.insert(s.size(), "L");
            num -= 50;
        }
        if (num == 0)
            return s;
        if (num / 40 != 0)
        {
            s.insert(s.size(), "XL");
            num -= 40;
        }
        if (num == 0)
            return s;
        while (num / 10 != 0)
        {
            s.insert(s.size(), "X");
            num -= 10;
        }
        if (num == 0)
            return s;
        if (num == 9)
        {
            s.insert(s.size(), "IX");
            return s;
        }
        if (num == 0)
            return s;
        if (num / 5 != 0)
        {
            s.insert(s.size(), "V");
            num -= 5;
        }
        if (num == 0)
            return s;
        if (num == 4)
        {
            s.insert(s.size(), "IV");
            return s;
        }
        if (num == 0)
            return s;
        while (num / 1 != 0)
        {
            s.insert(s.size(), "I");
            num -= 1;
        }

        return s;
    }
};