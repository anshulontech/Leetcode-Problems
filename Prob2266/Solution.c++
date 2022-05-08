// Link To The Problem:-
// https://leetcode.com/problems/count-number-of-texts/

// Solution:-

class Solution {
public:
    int countTexts(string s) {
        long long ans=1,mod=1e9+7;
        int n=s.size();
        
        for(int i=0;i<n;) {
            if(s[i]=='7' || s[i]=='9') {
                long long first=0,second=0,third=0,fourth=1;
                char c=s[i];
                while(i<n && s[i]==c) {
                    long long sum=first+second+third+fourth;
    
                    first=second%mod;
                    second=third%mod;
                    third=fourth%mod;
                    fourth=sum%mod;
                    i++;
                }

                ans*=fourth;
                ans%=mod;
            } else {
                long long first=0,second=0,third=1;
                char c=s[i];
                while(i<n && s[i]==c) {
                    long long sum=first+second+third;
    
                    first=second%mod;
                    second=third%mod;
                    third=sum%mod;
                    i++;
                }

                ans*=third;
                ans%=mod;
            }
            

        }
        
        return ans;
    }
};
