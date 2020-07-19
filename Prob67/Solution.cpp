#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool checkString(string &);

//addBinary Code Starts Here.

// Approach 1 :-

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res = "";

        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0)
        {
            int x = i >= 0 ? a[i] - '0' : 0;
            int y = j >= 0 ? b[j] - '0' : 0;

            res += to_string((x + y + carry) % 2);
            carry = (x + y + carry) / 2;

            i--, j--;
        }

        if (carry)
            res += '1';

        reverse(res.begin(), res.end());

        return res;
    }
};

// addBinary code ends here.

// Main Function

int main()
{
    Solution Result;
    string s1, s2;
    cout << "Enter binary string 1:-" << endl;
    cin >> s1;

    if (!checkString(s1))
    {
        cout << "Invalid String";
        exit(0);
    }

    cout << "Enter binary string 2:-" << endl;
    cin >> s2;

    if (!checkString(s2))
    {
        cout << "Invalid String";
        exit(0);
    }

    string ans = Result.addBinary(s1, s2);

    cout << "Your Final answer is:-" << endl;
    cout << ans;

    return 0;
}

bool checkString(string &s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] != '0' && s[i] != '1')
            return false;

    return true;
}
