int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

class Solution {



public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dis(n, vector<int>(m, -1));

          queue<pair<int, int> > pq;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0)
               {
                     pq.push({i, j});
                dis[i][j] = 0;
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

                if ( nr >= 0 && nr < n && nc >= 0 && nc < m && dis[nr][nc] ==-1 ) {
                    pq.push({nr, nc});
                    dis[nr][nc] = dis[r][c] + 1;
                }
            }
        }

        return dis;
    }
};
