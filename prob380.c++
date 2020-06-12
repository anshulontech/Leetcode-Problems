// https://leetcode.com/problems/insert-delete-getrandom-o1/

// Time Complexity:-O(1).  For each particular step else for full set it is O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     We are using an unordered_set for this approach to store the values.
// Insert function:-
//     If the value is not present than we will simply insert the value and return true else return false.
        
// Remove Function:-
//     For this we are calling a function name random whch will return us the random pointer for the set and we will 
// return the value associated with that pointer.

class RandomizedSet
{
private:
    unordered_set<int> store;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (store.find(val) != store.end())
            return false;

        store.insert(val);

        return true;
    }

    bool remove(int val)
    {
        if (store.find(val) != store.end())
        {
            store.erase(store.find(val));
            return true;
        }

        return false;
    }

    int getRandom()
    {
        return *Random();
    }

    unordered_set<int>::iterator Random()
    {
        int k = rand() % store.size();

        unordered_set<int>::iterator itr = store.begin();

        while (k)
        {
            itr++;
            k--;
        }

        return itr;
    }
};