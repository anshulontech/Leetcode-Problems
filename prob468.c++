// https://leetcode.com/problems/validate-ip-address/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

class Solution
{
public:
    string validIPAddress(string s)
    {
        if (count(s.begin(), s.end(), '.') == 3)
        {
            if (s[s.size() - 1] == '.')
                return "Neither";
            stringstream ss(s);
            string token;

            while (getline(ss, token, '.'))
            {
                if (token.length() == 0 || token.length() > 3)
                    return "Neither";
                if (token[0] == '0' && token.length() != 1)
                    return "Neither";
                for (char c : token)
                    if (!isdigit(c))
                        return "Neither";
                if (stoi(token) > 255)
                    return "Neither";
            }

            return "IPv4";
        }
        else if (count(s.begin(), s.end(), ':') == 7)
        {
            if (s[s.size() - 1] == ':')
                return "Neither";
            stringstream ss(s);
            string token;

            while (getline(ss, token, ':'))
            {
                if (token.length() == 0 || token.length() > 4)
                    return "Neither";
                for (char c : token)
                    if (!isxdigit(c))
                        return "Neither";
            }

            return "IPv6";
        }
        else
            return "Neither";
    }
};