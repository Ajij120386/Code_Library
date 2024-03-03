#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n, m, ii, jj, dis[N][N], dis1[N][N];
char c[N][N], c1[N][N];
bool vis[N][N];
queue<vector<int>>q;

int32_t main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      dis[i][j] = INT_MAX;
      dis1[i][j] = 0;
    }
  }

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
      if (c[i][j] == 'M') {
        q.push({i, j, 0});
      }
      if (c[i][j] == 'A') {
        ii = i, jj = j;
      }
    }
  }

  while (!q.empty()) {
    auto curr = q.front();
    int x = curr[0], y = curr[1], steps = curr[2];
    q.pop();
    if (x >= 1 && x <= n && y >= 1 && y <= m && c[x][y] != '#' && steps < dis[x][y]) {
      dis[x][y] = steps;
      for (int i = 0; i < 4; i++) {
        int xx = dx[i] + x;
        int yy = dy[i] + y;
        q.push({xx, yy, steps + 1});
      }
    }
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      vis[i][j] = false;
    }
  }

   for (int i = 1; i <= n; i++) {
     for (int j = 1; j <= m; j++) {
            if(dis[i][j]==INT_MAX) cout<<"X"<<" ";
      else cout << dis[i][j] << " ";
     }
     cout << "\n";
   }

  queue<pair<int, int>>q;
  q.push({ii, jj});
  vis[ii][jj] = true;
  c1[ii][jj] = '*';

  ii = -1, jj = -1;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    if (x == 1 || x == n || y == 1 || y == m) {
      ii = x, jj = y;
    }
    q.pop();
    for (int i = 0; i < 4; i++) {
      int xx = dx[i] + x;
      int yy = dy[i] + y;
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && vis[xx][yy] == false && c[xx][yy] == '.' && (dis1[x][y] + 1 < dis[xx][yy])) {
        dis1[xx][yy] = dis1[x][y] + 1;
        q.push({xx, yy});
        vis[xx][yy] = true;
        if (i == 0) {
          c1[xx][yy] = 'U';
        }
        else if (i == 1) {
          c1[xx][yy] = 'D';
        }
        else if (i == 2) {
          c1[xx][yy] = 'R';
        }
        else {
          c1[xx][yy] = 'L';
        }
      }
    }
  }

  if (ii == -1 && jj == -1) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
    string s;
    while (c1[ii][jj] != '*') {
      s += c1[ii][jj];
      if (s.back() == 'R') {
        --jj;
      }
      else if (s.back() == 'L') {
        ++jj;
      }
      else if (s.back() == 'U') {
        ++ii;
      }
      else {
        --ii;
      }
    }
    cout << s.size() << "\n";
    reverse(s.begin(), s.end());
    cout << s << "\n";
  }
  return 0;

}
