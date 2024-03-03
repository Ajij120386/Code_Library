#include <bits/stdc++.h>
using namespace std;
const int DX[4] = {-1, 0, 1, 0};
const int DY[4] = {0, 1, 0, -1};

int N, M;
int A[101][101];
int ans = INT_MAX;
int req;

int solve(const int i, const int j) {

   vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
   dist[i][j] = 0;
   int sum = 0;
   int found = 0;
   queue<pair<int, int>> q;
   q.push({i, j});
   while (!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
         int nx = r + DX[i];
         int ny = c + DY[i];
         if (nx >= 0 && nx < N && ny >= 0 && ny < M && A[nx][ny] != 2 && dist[nx][ny] == INT_MAX) {
            dist[nx][ny] = 1 + dist[r][c];
            if (A[nx][ny] == 1) {
               sum += dist[nx][ny];
               found++;
            }
            q.push({nx, ny});
         }
      }
   }
   if(found == req)
          return sum;
      return  INT_MAX;
}

int main() {


   cin >> N >> M;

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         cin >> A[i][j];
         if (A[i][j] == 1)
            req++;
      }
   }
   for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
         if (A[i][j] == 0)
            ans = min(ans, solve(i, j));

 if(ans == INT_MAX) cout<<-1<<endl;
  else cout<<ans << endl;

}
