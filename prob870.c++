// https://leetcode.com/problems/advantage-shuffle/

// Time Coplexity:-O(N*log(N)).
// Space Complexity:-O(N).
    
// Approach:-
//     In this problem initially we will store the count of each number of A in a map. Now we will sort the vector A . Now on 
// traversing the vector B we will make a combination such that the value of B[i] should be just less than that of the A[i] and 
// assign the value. If no such combination occurs than we will assign minimum value we have to it.  

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        cout<<A.size()<<" "<<B.size();
        unordered_map<int,int> count;
        for(int i=0;i<A.size();i++)
            count[A[i]]++;
        
        sort(A.begin(),A.end());
        
        vector<int> res;
        
        for(int i=0;i<B.size();i++)
        {
            int index=upper_bound(A.begin(), A.end(), B[i])-A.begin();
            if(index<B.size())
            {
                while(index<A.size() && count[A[index]]==0)
                    index++;
                if(index<B.size())
                {
                    res.push_back(A[index]);
                    count[A[index]]--;
                }
                else
                {
                    index=0;
                    while(index<A.size() && count[A[index]]==0)
                        index++;
                    
                    res.push_back(A[index]);
                    count[A[index]]--;
                }
            }
            else
            {
                index=0;
                while(index<A.size() && count[A[index]]==0)
                    index++;
                    
                res.push_back(A[index]);
                count[A[index]]--;
            }
        }
        
        return res;
    }
};

// Method 2:-

// Time Coplexity:-O(N*log(N)).
// Space Complexity:-O(N).
    
// Approch:-
//     Here instead of sorting and making a new array we are just using multiset. All the method is same as that above one 
// But here the advantage is that we are not going to use a hash map to store count and hence some memeory can be saved.

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s(begin(A),end(A));
        
        for(int i=0;i<B.size();i++)
        {
            auto p=*s.rbegin()<=B[i] ? s.begin() : s.upper_bound(B[i]);
            
            A[i]=*p;
            s.erase(p);
        }
        
        return A;
    }
};