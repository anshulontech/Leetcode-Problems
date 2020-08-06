// Approach 1:-

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& A) {
        unordered_map<int, int> store;

        for (int i=0;i<A.size();i++)
            store[A[i][0]]=i;

        sort(A.begin(), A.end());

        vector<int> res(A.size());

        for (int i=0;i<A.size();i++) {
            int index=binarySearch(A, A[i][1], i);

            if (index==A.size())
                res[store[A[i][0]]]=-1;
            else
                res[store[A[i][0]]]=store[A[index][0]];
        }

        return res;
    }

    int binarySearch(vector<vector<int>>& A, int& val, int start) {
        int end=A.size()-1;

        while (start<=end) {
            int mid=start+(end-start)/2;
            if (A[mid][0]==val)
                return mid;
            else
                if (A[mid][0]>val)
                    end=mid-1;
                else
                    start=mid+1;
        }

        return start;
    }
};