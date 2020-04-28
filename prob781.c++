// https://leetcode.com/problems/rabbits-in-forest/

// Time Compelxity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     We will try to store the count of each number in a map. If the nuber of times the answer[i] occur is a factor of nums[i]+1 
// than it represents that all rabbits of this kind are answering and hence no rabit of this kind is not answering and hence 
// rabbts of this kind are equal to count of nums[i]. If it is not a factor than number of rabbit of this kind are 
// (x.second/factor+1)*factor from referance 1 in code as it will be by maths. Else the code is clear and easy to understand.

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> store;
        int max=0;
        
        for(int i=0;i<answers.size();i++)
            store[answers[i]]++;
        
        for(auto x : store)
        {
            int factor=x.first+1;
            if(x.second%factor==0)
                max+=x.second;
            else
                max+=(x.second/factor+1)*factor;  // Referance 1
        }
        return max;
    }
};