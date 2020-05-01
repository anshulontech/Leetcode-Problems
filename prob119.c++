// https://leetcode.com/problems/pascals-triangle-ii/

// Time Complexity:-O(K^2).
// Space Complexity:-O(K^2).  -- Extra space is used.
    
// Approach:-
//     Using the property of pascal triangle will update the value on the behalf of previous row. 

class Solution {
public:
    vector<int> getRow(int k) {
        vector<int> values;
        values.push_back(1);
        
        while(k>0)
        {
            values=change(values);
            k--;
        }
        
        return values;
    }
    
private:
    
    vector<int> change(vector<int> & values)
    {
        vector<int> temp;
        temp.push_back(1);
        for(int i=0;i<values.size()-1;i++)
            temp.push_back(values[i]+values[i+1]);
        
        temp.push_back(1);
        
        return temp;
    }
};


// Time Complexity:-O(K^2).
// Space Complexity:-O(1).  -- No Extra space is used.

// Approach:-
    // Same as above but the difference is no extra Space is used.


class Solution {
public:
    vector<int> getRow(int k) {
        vector<int> values;
        values.push_back(1);
        if(k==0)
            return values;
        values.push_back(1);
        
        while(k>1)
        {
            change(values);
            k--;
        }
        
        return values;
    }
    
private:
    
    void change(vector<int> & values)
    {
        int first=values[0];
        int second=values[1];
        int i=1;
        for(;i<values.size()-1;i++)
        {
            int temp=first+second;
            first=values[i+1];
            second=values[i];
            values[i]=temp;
            
        }
        values[i]=first+second;
        values.push_back(1);
    }
};