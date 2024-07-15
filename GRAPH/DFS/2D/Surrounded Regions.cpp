
class Solution {
public:


  int delrow[4] = {-1, 0, +1, 0};
  int delcol[4] = {0, 1, 0, -1};
  int n,m;
 void dfs(int r, int c,vector<vector<int>>&vis,vector<vector<char>>& board)
 {

        vis[r][c]=1;




       // check for top, right, bottom, left
        for(int i = 0;i<4;i++) {
            int nrow = r+ delrow[i];
            int ncol = c+ delcol[i];
            // check for valid coordinates and unvisited Os
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m
            && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
             {
                dfs(nrow, ncol, vis, board);
            }
        }

 }
    void solve(vector<vector<char>>& board) {

        n = board.size();
         m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));

        // traverse first row and last row
        for(int j = 0 ; j<m;j++) {
            // check for unvisited Os in the boundary rows

            // first row
            if(!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board);
            }

            // last row
            if(!vis[n-1][j] && board[n-1][j] == 'O') {
                dfs(n-1,j,vis,board);
            }
        }

        for(int i = 0;i<n;i++) {
            // check for unvisited Os in the boundary columns
            // first column
            if(!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board);
            }

            // last column
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, vis, board);
            }
        }

        // if unvisited O then convert to X
        for(int i = 0;i<n;i++) {
            for(int j= 0 ;j<m;j++) {
                if(!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }


    }



};
