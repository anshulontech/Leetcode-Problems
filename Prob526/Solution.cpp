// Approach 1:-

class Solution {
private:
    int res=0;
    vector<bool> store;
public:
    int countArrangement(int N) {
        for (int i=0;i<N;i++)
            store.push_back(true);

        int pos=1;

        dfs(pos, N);

        return res;
    }

    void dfs(int& pos, int& N) {
        if (pos>N) {
            res++;
            return;
        }

        for (int i=0;i<N;i++) {
            if (!store[i] || !(pos%(i+1)==0 || (i+1)%pos==0))
                continue;
            store[i]=false;
            pos++;
            dfs(pos, N);
            pos--;
            store[i]=true;
        }

        return;
    }
};