class Solution {
public:
void dfs(vector<vector<char>>& board,int row,int col)
    {
        int n=board.size();
        int m=board[0].size();
        board[row][col]='#';
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m  && board[nrow][ncol]=='O')
            {
                dfs(board,nrow,ncol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        //first row
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
                dfs(board,0,j);
        }

        //last row
        for(int j=0;j<m;j++)
        {
            if(board[n-1][j]=='O')
                dfs(board,n-1,j);
        }

        //first col
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
                dfs(board,i,0);
        }

        //last column
         for(int i=0;i<n;i++)
        {
            if(board[i][m-1]=='O')
                dfs(board,i,m-1);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='#')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }


    }
};