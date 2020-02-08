// https://leetcode.com/problems/find-common-characters/


class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> B;
        while(A[0].size()!=0)
        {
            int count=1;
            for(int j=1;j<A[0].size();j++)
				if(A[0][0]==A[0][j])
                {
                	A[0].erase(j,1);
                	count++;
                	j--;
           		}
	
            int run;
            for(int i=1;i<A.size();i++)
            {
				run=0;
                for(int j=0;j<A[i].size();j++)
                    if(A[0][0]==A[i][j])
                        run++;
                
                if(run<count)
                    count=run;
            }
            string D=A[0].substr(0,1);
            
            while(count!=0)
            {
                B.push_back(D);
                count--;
            }
            
            A[0].erase(0,1);
        }
        
        return B;
    }
};