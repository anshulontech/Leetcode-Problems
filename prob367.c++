// https://leetcode.com/problems/valid-perfect-square/


//Method 1:-
//Time Complexity:-O(log(N)).
//Space Complexity:-O(1).
    
//Approach:-
//    In this betweeen the number we are using binary search to find the mid number . Than we will check that is it's square 
//is equal to nu or not, if it was than we will return true else if it's square is more than num than we apply binary search 
//for numbers greater than mid and less than num else if square is less than we will apply t for previous numbers . If the 
//value of left goes out more than that of right thn it represents that the given number is not a perfect square hence we 
//will return false in that condition else check for searching till number is not found.



class Solution {
public:
    bool isPerfectSquare(int num) {
        int first=num%10;
        
        if(first==2 | first== 3 || first==7 || first==8)
            return false;
        
        int left=1;
        int right=num;
        
        while(left<=right)
        {
            long long int mid=left+(right-left)/2;
            long long int sq=mid*mid;
            
            if(sq==num)
                return true;
            else
                if(sq<num)
                    left=mid+1;
                else
                    right=mid-1;
        }
        
        return false;
    }
};


// Method 2:-
    
// Time Complexity:-O(sqrt(N)).
// Space Complexity:-O(1).
    
// Approach:-
//     As we know that a perfect square is summation of numbers like 1+3+5+7+9+11+13... ans so on . Hece In this approach
//what we are going to do is check that is the summation of numbers comes out equal to num or not. If were found than we 
//return true else return false.

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1;
        while(num>0)
        {
            num-=i;
            i+=2;
        }
        
        return num==0;
    }
};