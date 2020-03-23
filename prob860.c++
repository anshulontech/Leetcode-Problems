// https://leetcode.com/problems/lemonade-change/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(3,0);
        
        for(int i=0;i<bills.size();i++)
            if(bills[i]==5)
                change[0]++;
            else
                if(bills[i]==10)
                    if(change[0]==0)
                        return false;
                    else
                    {
                        change[1]++;
                        change[0]--;
                    }
                else
                    if(change[0]==0||change[1]==0)
                        if(change[0]==0)
                            return false;
                        else
                            if(change[0]<3)
                                return false;
                            else
                            {
                                change[2]++;
                                change[0]=change[0]-3;
                            }
                    else
                    {
                        change[2]++;
                        change[1]--;
                        change[0]--;
                    }
        
        return true;
    }
};