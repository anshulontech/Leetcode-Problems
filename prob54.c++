// https://leetcode.com/problems/spiral-matrix/

// Time Complexity:-O(N*M).
// Space Complexity:-O(1).
    
// Approach:-
//     In this we are traversing the matrix in spiral form such that we will firts move for first row than move for 
// last column than for last row than for first column and than we reduced our matrix by removing the outer edges using 
// row and col variable and do same for the new matrix formed inside this matrix. 
        
//     The row and col works like as starting will take from row and the new end will form for n-row hence we will 
// reduce the matrix size by 2*row and same for col , Hence by reducing the matrix we can traverse the matrix in 
// spiral form.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> store;
        if(matrix.size()==0)
            return store;
        int m=matrix.size(),n=matrix[0].size();
        int num=m*n;
        
        int row=0,col=0,i=0,j=0;
        
        while(num) {
            i=row;
            j=col;
            
            while(num && j<(n-col)) {  // traversing the row in forward order.
                store.push_back(matrix[i][j++]);
                num--;
            }
            
            j--;
            i++;
            
            while(num && i<(m-row)){  // traversing the last col in top-down order.
                store.push_back(matrix[i++][j]);
                num--;
            }
                
            
            i--;
            j--;
            
            while(num && j>=col) {  // traversing the last column in reverse order.
                store.push_back(matrix[i][j--]);
                num--;
            }
            
            j++;
            i--;
            
            while(num && i>row) {  // traversing the first col in down-top order.
                store.push_back(matrix[i--][j]);
                num--;
            }
            
            row++;  // Increasing them to reduce the matrix by removing first and last row of current matrix
            col++;  // Increasing them to reduce the matrix by removing first and last column of current matrix
            
        }
        return store;
    }
};