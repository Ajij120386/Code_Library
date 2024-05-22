
//GFG QUESTION


class Solution {
  private:
    void dfs(int row, int col, vector < vector < int >> & vis,
      vector < vector < int >> & grid, vector < pair < int, int >> & vec, int row0,
      int col0) {
      // mark the cell as visited
      vis[row][col] = 1;

      // coordinates - base coordinates
      vec.push_back({
        row - row0,
        col - col0
      });
      int n = grid.size();
      int m = grid[0].size();

      // delta row and delta column
      int delrow[] = {-1, 0, +1, 0};
      int delcol[] = {0, -1, 0, +1};

      // traverse all 4 neighbours
      for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        // check for valid unvisited land neighbour coordinates
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
          !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
          dfs(nrow, ncol, vis, grid, vec, row0, col0);
        }
      }
    }
  public:
    int countDistinctIslands(vector < vector < int >> & grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector < vector < int >> vis(n, vector < int > (m, 0));
      set < vector < pair < int, int >>> st;

      // traverse the grid
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          // if not visited and is a land cell
          if (!vis[i][j] && grid[i][j] == 1) {
            vector < pair < int, int >> vec;
            dfs(i, j, vis, grid, vec, i, j);
            // store in set
            st.insert(vec);
          }
        }
      }
      return st.size();
    }
};

//LEETCODE QUESTIOM
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
void dfs(int r,int c,vector<vector<char>>& grid)
{

     vis[r][c]=1;

     for(int i=0;i<4;i++)
     {
        int nr=r+dx[i];
        int nc=c+dy[i];

       if(valid(nr,nc,grid))
        dfs(nr,nc,grid);
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
                dfs(i,j,grid);

            }
       }

       }

    return cnt;
    }
};
