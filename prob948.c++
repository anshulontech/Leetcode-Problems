// https://leetcode.com/problems/bag-of-tokens/description/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(1).
    
// Approach:-
//     In this first we will sort the tokens array and than set pointers ate the first and last element , now if we 
// have power to be greater than tokens[start] than we will loose power first and gain points but if we have no enough 
// power than we will loose 1 point and get the max unused power and than again continue the loop till we not traversed 
// the whole tokens.

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int res=0,start=0,end=tokens.size()-1,points=0;
        sort(tokens.begin(),tokens.end());
        while(start<=end) {
            if(P>=tokens[start]) {
                P-=tokens[start++];
                res=max(res,++points);
            }
            else
                if(points>0) {
                    points--;
                    P+=tokens[end--];
                }
                else
                    break;
        }
        
        return res;
    }
};