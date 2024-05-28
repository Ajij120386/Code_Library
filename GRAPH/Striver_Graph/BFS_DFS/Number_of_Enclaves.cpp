int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

          queue<pair<int, int> > pq;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if ( (i==0 || i==n-1 || j==m-1|| j==0) && grid[i][j] ==1)
               {
                     pq.push({i, j});
                    vis[i][j] = 1;
               }
            }
        }
        while (!pq.empty()) {
            int r = pq.front().first;
            int c = pq.front().second;
            pq.pop();

            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if ( nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] ==0 && grid[nr][nc]==1) {
                    pq.push({nr, nc});
                    vis[nr][nc] =  1;
                }
            }
        }
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

               if(vis[i][j]==0 && grid[i][j]==1)  cnt++;
            }
        }
        return cnt;
    }

};
