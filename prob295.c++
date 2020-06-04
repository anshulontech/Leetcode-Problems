// https://leetcode.com/problems/find-median-from-data-stream/

// Time Complexity:-O(log(N)).
// Space Comlexity:-O(N).
    
// Approach:-
//     In this we are using two heaps one of tem is min heap and the other one is max heap. They are used to store 
// the valus such that the min heap stores the values greater than the meadian while max_heap stores values less than 
// median or equal to. Now how we are manipualtng the heap is that during addition we will first add num to the max
// heap and remove it from max heap and insert it in min heap till their size difference will not become less than 2 . 
// After all this we will check the condition that is their top values are in right order or not. If they are not than 
// we will swap tham else leave on their state. During finding median if both container size are same than we will 
// return their average else return the value of top where container size is greater.

class MedianFinder {
private:
    priority_queue<int> store_min;
    priority_queue<int,vector<int> , greater<int>> store_max;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        store_min.push(num); 
        while((store_min.size()-store_max.size())!=0 && (store_min.size()-store_max.size())!=1 && (store_min.size()-store_max.size())!=-1) {
            int temp=store_min.top();
            store_min.pop();
            store_max.push(temp);
        }
        
        
    if((!store_min.empty() && !store_max.empty()) &&  store_min.top()>store_max.top()) {
        int temp=store_min.top();
        store_min.pop();
        int temp2=store_max.top();
        store_max.pop();
        store_min.push(temp2);
        store_max.push(temp);
    }
    }
    
    double findMedian() {
        if(store_min.size()==store_max.size())
            return double(store_min.top()+store_max.top())/2;
        else
            if(store_min.size()<store_max.size())
                return double(store_max.top());
            else
                return double(store_min.top());
    }
};