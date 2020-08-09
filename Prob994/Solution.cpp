// Approach 1:-

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        int r=grid.size(), c=grid[0].size(), fresh=0, t=0;

        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++)
                if (grid[i][j]==2)
                    q.push({ i, j });
                else if (grid[i][j]==1)
                    fresh++;

        while (!q.empty()) {
            int N=q.size();

            for (int i=0;i<N;i++) {
                int x=q.front().first, y=q.front().second;
                q.pop();

                if (x>0 && grid[x-1][y]==1) grid[x-1][y]=2, fresh--, q.push({ x-1, y });

                if (y>0 && grid[x][y-1]==1) grid[x][y-1]=2, fresh--, q.push({ x, y-1 });

                if (x<r-1 && grid[x+1][y]==1) grid[x+1][y]=2, fresh--, q.push({ x+1, y });

                if (y<c-1 && grid[x][y+1]==1) grid[x][y+1]=2, fresh--, q.push({ x, y+1 });
            }

            if (!q.empty())
                t++;
        }


        return fresh==0?t:-1;
    }
};