// https://leetcode.com/problems/design-hashset/

class MyHashSet {
private:
    vector<vector<int> * > set;
    const int size=500;
public:
    MyHashSet() {
        set.resize(size);
    }
    
    void add(int key) {
        int index=key%size;
        if(!contains(key)) {
            auto v=set[index];
            if(v==nullptr) 
                v=new vector<int> ;
            
            v->push_back(key);
            set[index]=v;
        }
    }
    
    void remove(int key) {
        int index=key%size;
        auto v=set[index];
        
        if(v==nullptr)
            return;
        
        for(auto itr=v->begin(); itr!=v->end();itr++)
            if(*itr==key) {
                v->erase(itr);
                return ;
            }
        
        return ;
    }
    
    bool contains(int key) {
        int index=key%size;
        auto v=set[index];
        
        if(v==nullptr)
            return false;
        
        for(auto e : *v) 
            if(e==key)
                return true;
        
        return false;
    }
};