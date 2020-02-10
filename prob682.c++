// https://leetcode.com/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& A) {
        stack<int> scores;
        int sum=0;
        for(int i=0;i<A.size();i++)
        {
            auto s=A[i];
            if(s=="+")
            {
                int x=scores.top();
                scores.pop();
                int y=scores.top();
                sum=sum+x+y;
                scores.push(x);
                scores.push(x+y);
            }
            else
                if(s=="D")
                {
                    int x=scores.top();
                    sum=sum+x*2;
                    scores.push(x*2);
                }
                else
                    if(s=="C")
                    {
                        int x=scores.top();
                        sum=sum-x;
                        scores.pop();
                    }
                    else
                    {
                        int x=stoi(s);
                        scores.push(x);
                        sum=sum+x;
                    }
        }
        
        return sum;
    }
        
        
};