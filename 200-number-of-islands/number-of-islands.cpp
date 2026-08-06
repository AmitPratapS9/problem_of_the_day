class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int row,int col)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1 && grid[nrow][ncol]=='1')
            {
                dfs(grid,vis,nrow,ncol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]!=1)
                {
                    cnt++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    
    }
};