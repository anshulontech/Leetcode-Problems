// https://leetcode.com/problems/majority-element/

// Method 1:- Using Moore's Algorithm

// Time Complexity;-O(N).
// Space Complexity;-O(1).
    
// Help:-
//     https://www.youtube.com/watch?v=n5QY3x_GNDg
    

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=nums[0],count=1;
        
        for(int i=1;i<nums.size();i++)
            if(nums[i]==maj)
                count++;
            else
            {
                count--;
                if(count==0)
                {
                    maj=nums[i];
                    count=1;
                }
                else
                    continue;
            }
        
        return maj;
    }
};

// Method 2:- Can be used using hash map as we will store the count of each element and than on traversing the map we will 
// check that is any number has more than N/2 occurances or not .

// Method 3:-
// We will first sort the array and than check for the occurance of each nuber if any number was found to have more than N/2 
// occurance than we will return that number.

// Method 4:- Using bit masking

// Help:-
// https://www.youtube.com/watch?v=0s3zqYaDInE

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=0;
        for(unsigned int i=0,mask=1;i<32;i++,mask<<=1)
        {
            int bits=0;
            for(int num :nums)
                if(num & mask)
                    bits++;
            
            if(bits > nums.size()/2)
                majority |= mask;
            
        }
        
        return majority;
    }
};