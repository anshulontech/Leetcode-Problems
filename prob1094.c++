// https://leetcode.com/problems/car-pooling/

// Method 1:-

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
//     As we have limited stations in our trip hence we are going to store the total number of passengers goes into the bus or 
// comes out from the bus in avector at their respective poisitions of the stand at which they come in or goes out. After this 
// we will traverse that vector to count the maximum number of passangers which had come in the bus. We have to check it at each 
// step as this will provide us that till that step what is maximum number of passengers that had arrived their.
    
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> store(1001);
        
        for(int i=0;i<trips.size();i++)
        {
            store[trips[i][1]]+=trips[i][0];
            store[trips[i][2]]-=trips[i][0];
        }
        
        int sum=0;
        for(int i=1;i<1001;i++)
        {
            sum+=store[i];
            if(sum>capacity)
                return false;
        }
        
        return true;
    }
};


// Method:-2 

// Time Complexity:-O(N*log(n)).
// Space Complexity:-O(N).

// Approach:-
//     In this first we wil sort the vector with referance to index 1 of the vector . Now will itterate the vector and at each 
// step will increase the count of passangers by the number of passengers entered at that step. Now As usual we will check the 
// condition that is count is greater than capacity or not . Now if it is than we will return false else we will move forward.
// Now the situation is that we had entered the passengers in the bus but how to reove them . this can be done with the help
// of priority queue(min heap). in this we are storing the values with referance to 2nd index. Now if the curr station is 
// greater than heap top element than we will first remove the passengers and go forward and so on. 

// NOTE:- I was not able to code it as don't know how to sort vector of vector in c++ with referance to any index.
