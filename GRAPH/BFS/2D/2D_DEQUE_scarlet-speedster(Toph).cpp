#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int mx = 102, INF = 1e9;
int g[mx][mx], n, m;
int d[mx][mx];
int bfs01(int A, int ty) {
	int sx = 0, sy = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			d[i][j] = INF;
		}
	}

	deque<pair<int, int>> q;
	d[sx][sy] = 0;
	q.push_front({sx, sy});
	while (!q.empty()) {

		auto [x, y] = q.front(); q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				int w = 0;
				if (abs(g[nx][ny] - g[x][y]) % 2 != ty)
                    w = A;
				if (d[x][y] + w < d[nx][ny]) {
					d[nx][ny] = d[x][y] + w;
					if (w != 0) {
						q.push_back({nx, ny});
					} else {
						q.push_front({nx, ny});
					}
				}
			}
		}
	}
	return d[n - 1][m - 1];
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t; while (t--) {
		int A, B; cin >> n >> m >> A >> B;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
			}
		}
		int flash = bfs01(A, 0), rflash = bfs01(B, 1);
		if (flash < rflash) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
