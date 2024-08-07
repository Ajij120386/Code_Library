#include <bits/stdc++.h>
using namespace std;

  void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid)
  {

      // mark it visited
              vis[row][col] = 1;
      queue<pair<int,int>> q;

          // push the node in queue
      q.push({row, col});
        int n = grid.size();
         int m = grid[0].size();

      // until the queue becomes empty
      while(!q.empty()) {

          int row = q.front().first;
          int col = q.front().second;
          q.pop();

          // traverse in the neighbours and mark them if its a land

          for(int delrow = -1; delrow<=1;delrow++)
          {
              for(int delcol = -1; delcol <= 1; delcol++)
               {
                      int nrow = row + delrow;
                      int ncol = col + delcol;

                      // neighbour row and column is valid, and is an unvisited land
                     if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                          && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                          {
                             vis[nrow][ncol] = 1;
                              q.push({nrow, ncol});
                           }
                }
           }
       }
  }

int main() {

    // n: row, m: column
    vector<vector<char>> grid
    {
        {'0', '1', '1', '1', '0', '0', '0'},
        {'0', '0', '1', '1', '0', '1', '0'}
    };


         int n = grid.size();
          int m = grid[0].size();

        // create visited array and initialise to 0

        vector<vector<int>> vis(n, vector<int>(m, 0));
              int cnt = 0;

        for(int row = 0; row < n ; row++) {
              for(int col = 0; col < m ;col++) {

                // if not visited and is a land
                if(!vis[row][col] && grid[row][col] == '1')
                {
                       cnt++;
                       bfs(row, col, vis, grid);
                }
            }
        }


    cout << cnt << endl;

    return 0;
}


//LEETCODE QUESTION

class Solution {
public:

int n,m;
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
bool vis[301][301];

bool valid(int x,int y, vector<vector<char> >& grid)
{

 return (x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]=='1');

}
void bfs(int r,int c,vector<vector<char>>& grid)
{
 
     vis[r][c]=1;
     queue<pair<int,int> >q;

     q.push({r,c});

     while(!q.empty())
     {
        int r=q.front().first;
         int c=q.front().second;
         q.pop();


         for(int i=0;i<4;i++)
     {
        int nr=r+dx[i];
        int nc=c+dy[i];
       
       if(valid(nr,nc,grid))
       {
         
       

        vis[nr][nc]=1;
        q.push({nr,nc});
       }
       
     }

     }

     

     
}

    int numIslands(vector<vector<char>>& grid) {
       
        
          n=grid.size();
           m=grid[0].size();
       
        int cnt=0;

       for(int i=0;i<n;i++)
       {

        for(int j=0;j<m;j++)
       {
        
            if(!vis[i][j] && grid[i][j]=='1')
            {
                 cnt++;
                bfs(i,j,grid);
               
            }
       }

       }
        
    return cnt;
    }
};