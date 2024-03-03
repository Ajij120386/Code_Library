#include <bits/stdc++.h>
using namespace std;

bool bipartiteDfs(int node, vector<int> adj[], int color[]) {

    for(auto it : adj[node]) {

        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!bipartiteDfs(it, adj, color)) {
                return false;
            }
        } else if(color[it] == color[node]) return false;
    }
    return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}


	int color[n];
    memset(color, -1, sizeof color);
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            if(!bipartiteDfs(i, adj, color)) {

                cout<<"No"<<endl;
                return 0;
            }
        }
    }

	cout<<"Yes"<<endl;
	return 0;
}



/*

4 3
1 2
2 3
1 3
output: not bipartite

5 2
1 2
3 4

Yes bipartite

*/
