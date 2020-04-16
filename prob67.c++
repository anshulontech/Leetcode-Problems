// https://leetcode.com/problems/add-binary/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     Initially we will make the size of both the string to be equal. To do so we are going to insert 0 at the beginning of 
// the small size string. After this we will make another string named s and initialize it with NULL. After this we will run 
// loop from the back side of the string and perforn addition operation to it. If any one of the character is 0 and the other 
// one is 1 than we will push 1 to string s or if both of them are 0 than add 0 to the string s. If both of the charaters are 
// 1 than we will insert 0 to the string s and got 1 as carry. Now to remove this carry we will move backward until we will 
// not encountered with 0 in any of the string. As we will encounter with 0 in the string we will assign that one to 1 and 
// increase the value of i so that while decreaseing it will again refer to it and the suitable operation can be performed to 
// it.  *** While moving backward in serach of 0 in the string we are going to insert 1 in the string because we dont want to 
// traverse it again and 1+1 with 1 carry givs 1 and 1 carry again.
        
// NOTE:-
//     All inserttions in the string are done on the 0th index.
    
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size())
            while(a.size()!=b.size())
                a.insert(0,"0");
        else
            while(a.size()!=b.size())
                b.insert(0,"0");
        
        
        string s="";
        
        for(int i=a.size()-1;i>=0;i--)
            if(a[i]=='0')
                if(b[i]=='0')
                    s.insert(0,"0");
                else
                    s.insert(0,"1");
            else
                if(b[i]=='0')
                    s.insert(0,"1");
                else
                {
                    s.insert(0,"0");
                    i--;
                    while(i>=0&&a[i]=='1'&&b[i]=='1')
                    {
                        s.insert(0,"1");
                        i--;
                    }
                    
                    if(i<0)
                        s.insert(0,"1");
                    else
                    {
                        if(a[i]=='0')
                            a[i]='1';
                        else
                            b[i]='1';
                        i++;
                    }
                }
        
        return s;
    }
};