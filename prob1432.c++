// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/

// Time Complexity:-O(3*N).  Where N is nuber of digits in num.
// Space Complexity:-O(1).
    
// Approach:- 
//     We will store the maximum form of a number in first variable and minimum form in second variable and store them . The code 
// is Commented to explain an also easy to understand.

class Solution {
public:
    int maxDiff(int num) {
        int len=checklength(num);
        int first=makemax(num,len);
        int second=makemin(num,len);
        
        cout<<first<<endl;
        cout<<second;
        
        return first-second;
    }
    
    int checklength(int num)  //  Function to check length os number.
    {
        int len=1;
        while(num/10>0)
        {
            num=num/10;
            len++;
        }
        
        return len;
    }
     
    int makemax(int num,int len)  // Function to change it into the maximun number
    {
        int temp=num;
        int l=len;
        
        int z=pow(10,l-1);
        int x=temp/z;
        temp=temp%z;
        
        while(l>1 && x==9)  // Determining the first non 9 element as if make this to 9 than it will become maximum.
        {
            l--;
            z=pow(10,l-1);
            x=temp/z;
            temp=temp%z;
        }
        
        if(x==9)
            return num;  // if x==9 than it represents that t.e whole number contains only 9a digit hence we can not make it ma xbecaue it was already/
        else
            return change(num,len,x,9);  // If it was not already max than we will change it
    }
    
    int makemin(int num,int len)  // Function to make it min.
    {
        int temp=num;
        int l=len;
        
        int z=pow(10,l-1);
        int x=temp/z;
        temp=temp%z;
        
        while(l>1 && (x==1 || x==0))
        {
            l--;
            z=pow(10,l-1);
            x=temp/z;
            temp=temp%z;
        }
        
        
        if(x==1)
            return num;
        else
            if(l==len)
                return change(num,len,x,1);
            else
                return change(num,len,x,0);
    }
    
    int change(int num,int len,int y,int val)  // Function to convert
    {
        int temp=num;
        int l=len;
        
        while(l>0)
        {
            int z=pow(10,l-1);
            int x=temp/z;
            temp=temp%z;
            if(x==y)
            {
                int a=pow(10,l);
                int pre=num/a;
                pre=pre*a;
                num=pre+val*z+temp;
            }
            l--;
        }
        
        return num;
    }
};