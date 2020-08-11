// Approach 1:-

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size()!=t.size())
            return false;
        vector<int> store(26, -1);

        for (int i=0;i<s.size();i++) {
            if (s[i]==t[i]) {
                continue;
            }

            int diff=t[i]-s[i] > 0 ? t[i]-s[i] : 26+t[i]-s[i];

            store[diff]++;

            if ((store[diff])*26+diff>k)
                return false;
        }

        return true;
    }
};