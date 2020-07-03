// https://leetcode.com/problems/prison-cells-after-n-days/description/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        bool hasCycle=false;
        int cycle=0;
        
        unordered_set<string> Set;
        
        for(int i=0;i<N;i++) {
            vector<int> next=nextDay(cells);
            
            string key = make_string(next);
            if(Set.find(key)==Set.end()) {
                Set.insert(key);
                cycle++;
            }
            else {
                hasCycle=true;
                break;
            }
            
            cells=next;
        }
        
        if(hasCycle) {
            N%=cycle;
            for(int i=0;i<N;i++)
                cells=nextDay(cells);
        }
        
        return cells;
    }
    
    vector<int> nextDay(vector<int> & cells) {
        vector<int> temp(cells.size());
        
        for(int i=1;i<cells.size()-1;i++)
            temp[i]=cells[i-1]==cells[i+1] ? 1 : 0;
        
        return temp;
    }
    
    string make_string ( vector<int> & store) {
        string temp="";
        
        for(int i=0;i<store.size();i++)
            temp+=to_string(store[i]);
        
        return temp;
    }
};