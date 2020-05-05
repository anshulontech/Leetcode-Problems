// https://leetcode.com/problems/powerful-integers/

// Approach:-
//     For this we will use brute force approch such that we have to try each combination that is this satisfy or not. Taking 0 
// power for x and y both and increasing y till it will remain less than bound after this incrementing x and making y 0 and 
// follow as mentioned above. But the question is till what point we have to follow this . This is easy by applying a variable 
// flag which change the value when any cobination is inserted or not if it was not than it represents the end of the loop and 
// at that time we can exit the the loop and the final answer is in our hand. Buttheir is twist like what if any on or both are 
// 1 than in this case we are using a substitue function which is used to handel such situations.

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(x==1 || y==1)
        {
            return substitute(x*y,bound);
        }
        vector<int> res;
        unordered_set<int> store;
        int flag=0;
        for(int i=0;flag==0;i++)
        {
            flag=1;
            int help=pow(x,i);
            for(int j=0;;j++)
            {
                int temp=pow(y,j);
                if(help+temp<=bound)
                {
                    flag=0;
                    store.insert(help+temp);
                }
                else
                    break;
            }
            
        }
        
        for(auto x: store)
            res.push_back(x);
        
        return res;
    }
    
    vector<int> substitute(int num,int bound)
    {
        vector<int> store;
        if(num==1&& bound>1)
        {
            store.push_back(2);
            return store;
        }
        for(int i=0;;i++)
        {
            int temp=pow(num,i)+1;
            if(temp<=bound)
                store.push_back(temp);
            else
                return store;
        }
        
        return store;
                
    }
};